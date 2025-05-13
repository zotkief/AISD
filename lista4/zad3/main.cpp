#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class RB_BST {
private:
    enum Color { RED, BLACK };

    struct Node {
        int key;
        Color color;
        Node* left;
        Node* right;
        Node* parent;

        Node(int k = 0, Color c = BLACK, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr)
            : key(k), color(c), left(l), right(r), parent(p) {}
    };

    Node* root;
    Node* nil; 

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nil) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nil) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nil) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nil) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void insertFixup(Node* z) {
        while (z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateRight(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nil) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        v->parent = u->parent;
    }

    Node* minimum(Node* x) {
        while (x->left != nil) x = x->left;
        return x;
    }

    void deleteFixup(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

public:
    int size=30;
    RB_BST() {
        nil = new Node();
        nil->color = BLACK;
        nil->left = nil->right = nil->parent = nil;
        root = nil;

        left_trace= (char*)malloc( size*sizeof(char) );
        right_trace= (char*)malloc( size*sizeof(char) );
        for(int i=0; i<=size; i++){
            left_trace[i]=' ';
            right_trace[i]=' ';
        }
    }

    void insert(int key) {
        Node* z = new Node(key, RED, nil, nil, nil);
        Node* y = nil;
        Node* x = root;
        while (x != nil) {
            y = x;
            if (z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->parent = y;
        if (y == nil) root = z;
        else if (z->key < y->key) y->left = z;
        else y->right = z;
        insertFixup(z);
    }

    void deleteKey(int key) {
        Node* z = root;
        while (z != nil && z->key != key) {
            if (key < z->key) z = z->left;
            else z = z->right;
        }
        if (z == nil) return; 

        Node* y = z;
        Node* x;
        Color yOriginalColor = y->color;
        if (z->left == nil) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nil) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z)
                x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (yOriginalColor == BLACK)
            deleteFixup(x);
    }

    char* left_trace; 
    char* right_trace;
    void print_BST(Node * root, int depth,char prefix){
        if( root == nil ) return;
        if( root->left != nil ){
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
        if( root->right != nil ){
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
        RB_BST tree;
        std::vector<int> deleteOrder = data;

        for (int key : data) {
            std::cout << "insert " << key << "\n";
            tree.insert(key);
            tree.print();
            std::cout << "------------------\n";
        }

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
        RB_BST tree;
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