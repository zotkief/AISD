#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    int size=30;

    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else // duplikaty trafiają na prawo
            node->right = insert(node->right, key);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node)
            return nullptr;
        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* minNode = findMin(node->right);
                node->key = minNode->key;
                node->right = deleteNode(node->right, minNode->key);
            }
        }
        return node;
    }

    int height(Node* node) {
        if (!node)
            return -1; // zgodnie z konwencją: wysokość pustego drzewa to -1
        return 1 + max(height(node->left), height(node->right));
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

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
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