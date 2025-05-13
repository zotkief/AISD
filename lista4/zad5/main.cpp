#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

#define COMPARE_KEYS(a, b) (comparisons++, (a) < (b))
#define COMPARE_EQ(a, b) (comparisons++, (a) == (b))
#define PTR_ASSIGN(a, b) do { pointerChanges++; (a) = (b); } while(0)


struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int k) : key(k), left(nullptr), right(nullptr),parent(nullptr) {}
};

class BST {
private:
    Node* root;
    int size=30;

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    int height(Node* node) {
        if (!node)
            return -1; // zgodnie z konwencją: wysokość pustego drzewa to -1
        return 1 + max(height(node->left), height(node->right));
    }

    void splay(Node* x)
    {
        while(x->parent)
        {
            Node *y=x->parent;
            if(x==y->left && y==root)
            {
                rotateRight(y);
                cout<<"1"<<endl;
            }
            else if(x==y->right && y==root)
            {
                rotateLeft(y);
                cout<<"2"<<endl;
            }
            else if(x==y->left && y->parent->left==y)
            {
                rotateRight(y->parent);
                rotateRight(y);
                cout<<"3"<<endl;
            }
            else if(x==y->right && y->parent->right==y)
            {
                rotateLeft(y->parent);
                rotateLeft(y);
                cout<<"4"<<endl;
            }
            else if(x==y->right && y->parent->left==y)
            {
                rotateLeft(y);
                cout<<"5"<<endl;
                rotateRight(y->parent);
            }
            else if(x==y->left && y->parent->right==y)
            {
                rotateRight(y);
                cout<<"6"<<endl;
                rotateLeft(y->parent);
            }
        }
        root=x;
    }

public:
    BST() : root(nullptr) {
        left_trace= (char*)malloc( size*sizeof(char) );
        right_trace= (char*)malloc( size*sizeof(char) );
        for(int i=0; i<=size; i++){
            left_trace[i]=' ';
            right_trace[i]=' ';
        }
    }
    void deleteKey(Node** nodeRef, int key) {
        Node* node = *nodeRef;
        if (!node) return;
    
        if (key < node->key) {
            deleteKey(&node->left, key);
        }
        else if (key > node->key) {
            deleteKey(&node->right, key);
        }
        else {
            Node* parent = node->parent;
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                *nodeRef = temp;
                if (temp) temp->parent = parent;
                if (parent) splay(parent);
            } else {
                Node* minNode = findMin(node->right);
                node->key = minNode->key;
                deleteKey(&node->right, minNode->key);
                splay(node);
            }
        }
    }
    
    void deleteKey(int key){deleteKey(&root,key);}
    
    void insert(int key) {
        Node* z = new Node(key);
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            if (z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->parent = y;
        if (y == nullptr) root = z;
        else if (z->key < y->key) y->left = z;
        else y->right = z;

        splay(z);
    }

    int height() {
        return height(root);
    }

    char* left_trace; // needs to be allocaded with size
    char* right_trace; // needs to be allocaded with size


    void print_BST(Node * root, int depth,char prefix){
        if( root == NULL ) return;
        if( root->left != NULL ){
            print_BST(root->left, depth+1, '/');
        }
        if(prefix == '/') left_trace[depth-1]='|';
        if(prefix == '\\') right_trace[depth-1]=' ';
        if( depth==0) printf("-");
        if( depth>0) printf(" ");
        for(int i=0; i<depth-1; i++)
            if( left_trace[i]== '|' || right_trace[i]=='|' ) {
            printf("| ");
            } else {
            printf("  ");
            }
        if( depth>0 ) printf("%c-", prefix);
        printf("[%d]\n", root->key);
        left_trace[depth]=' ';
        if( root->right != NULL ){
            right_trace[depth]='|';
            print_BST(root->right, depth+1, '\\');
        }
    }
    void print(){
        print_BST(root,0,' ');
    }
    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }
};

int main() {
    const int n = 30;
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i)
        data[i] = i + 1;

    std::cout << "==== PRZYPADEK 1: insert w kolejnosci rosnacej, delete w permutacji ====\n";
    {
        BST tree;
        std::vector<int> deleteOrder = data;

        // Wstawianie w kolejności rosnącej
        for (int key : data) {
            std::cout << "insert " << key << "\n";
            tree.insert(key);
            tree.print();
            std::cout << "------------------\n";
        }

        // Permutacja usuwania
        std::shuffle(deleteOrder.begin(), deleteOrder.end(), std::mt19937(std::random_device{}()));

        for (int key : deleteOrder) {
            std::cout << "delete " << key << "\n";
            tree.deleteKey(key);
            tree.print();
            std::cout << "------------------\n";
        }
    }

    std::cout << "\n==== PRZYPADEK 2: insert i delete w losowej permutacji ====\n";
    {
        BST tree;
        std::vector<int> insertOrder = data;
        std::vector<int> deleteOrder = data;

        std::mt19937 rng(std::random_device{}());
        std::shuffle(insertOrder.begin(), insertOrder.end(), rng);
        std::shuffle(deleteOrder.begin(), deleteOrder.end(), rng);

        for (int key : insertOrder) {
            std::cout << "insert " << key << "\n";
            tree.insert(key);
            tree.print();
            std::cout << "------------------\n";
        }

        for (int key : deleteOrder) {
            std::cout << "delete " << key << "\n";
            tree.deleteKey(key);
            tree.print();
            std::cout << "------------------\n";
        }
    }

    return 0;
}