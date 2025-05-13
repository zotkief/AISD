#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

long long comparisons = 0;
long long pointerChanges = 0;

#define COMPARE_KEYS(a, b) (comparisons++, (a) < (b))
#define COMPARE_EQ(a, b) (comparisons++, (a) == (b))
#define PTR_ASSIGN(a, b) do { pointerChanges++; (a) = (b); } while(0)

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
        Node* y;
        PTR_ASSIGN(y, x->right);
        PTR_ASSIGN(x->right, y->left);
        if (y->left != nil) PTR_ASSIGN(y->left->parent, x);
        PTR_ASSIGN(y->parent, x->parent);
        if (x->parent == nil) PTR_ASSIGN(root, y);
        else if (x == x->parent->left) PTR_ASSIGN(x->parent->left, y);
        else PTR_ASSIGN(x->parent->right, y);
        PTR_ASSIGN(y->left, x);
        PTR_ASSIGN(x->parent, y);
    }

    void rotateRight(Node* x) {
        Node* y;
        PTR_ASSIGN(y, x->left);
        PTR_ASSIGN(x->left, y->right);
        if (y->right != nil) PTR_ASSIGN(y->right->parent, x);
        PTR_ASSIGN(y->parent, x->parent);
        if (x->parent == nil) PTR_ASSIGN(root, y);
        else if (x == x->parent->right) PTR_ASSIGN(x->parent->right, y);
        else PTR_ASSIGN(x->parent->left, y);
        PTR_ASSIGN(y->right, x);
        PTR_ASSIGN(x->parent, y);
    }

    void insertFixup(Node* z) {
        while (z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y;
                PTR_ASSIGN(y, z->parent->parent->right);
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    PTR_ASSIGN(z, z->parent->parent);
                } else {
                    if (z == z->parent->right) {
                        PTR_ASSIGN(z, z->parent);
                        rotateLeft(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateRight(z->parent->parent);
                }
            } else {
                Node* y;
                PTR_ASSIGN(y, z->parent->parent->left);
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    PTR_ASSIGN(z, z->parent->parent);
                } else {
                    if (z == z->parent->left) {
                        PTR_ASSIGN(z, z->parent);
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
        if (u->parent == nil) PTR_ASSIGN(root, v);
        else if (u == u->parent->left) PTR_ASSIGN(u->parent->left, v);
        else PTR_ASSIGN(u->parent->right, v);
        PTR_ASSIGN(v->parent, u->parent);
    }

    Node* minimum(Node* x) {
        while (x->left != nil) PTR_ASSIGN(x, x->left);
        return x;
    }

    void deleteFixup(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w;
                PTR_ASSIGN(w, x->parent->right);
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    PTR_ASSIGN(w, x->parent->right);
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    PTR_ASSIGN(x, x->parent);
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        PTR_ASSIGN(w, x->parent->right);
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(x->parent);
                    PTR_ASSIGN(x, root);
                }
            } else {
                Node* w;
                PTR_ASSIGN(w, x->parent->left);
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    PTR_ASSIGN(w, x->parent->left);
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    PTR_ASSIGN(x, x->parent);
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        PTR_ASSIGN(w, x->parent->left);
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    PTR_ASSIGN(x, root);
                }
            }
        }
        x->color = BLACK;
    }

public:
    int size = 30;
    RB_BST() {
        nil = new Node();
        nil->color = BLACK;
        PTR_ASSIGN(nil->left, nil);
        PTR_ASSIGN(nil->right, nil);
        PTR_ASSIGN(nil->parent, nil);
        PTR_ASSIGN(root, nil);

        left_trace = (char*)malloc(size * sizeof(char));
        right_trace = (char*)malloc(size * sizeof(char));
        for (int i = 0; i <= size; i++) {
            left_trace[i] = ' ';
            right_trace[i] = ' ';
        }
    }

    void insert(int key) {
        Node* z = new Node(key, RED, nil, nil, nil);
        Node* y;
        PTR_ASSIGN(y, nil);
        Node* x;
        PTR_ASSIGN(x, root);
        while (x != nil) {
            PTR_ASSIGN(y, x);
            if (COMPARE_KEYS(z->key, x->key)) PTR_ASSIGN(x, x->left);
            else PTR_ASSIGN(x, x->right);
        }
        PTR_ASSIGN(z->parent, y);
        if (y == nil) PTR_ASSIGN(root, z);
        else if (COMPARE_KEYS(z->key, y->key)) PTR_ASSIGN(y->left, z);
        else PTR_ASSIGN(y->right, z);
        insertFixup(z);
    }

    void deleteKey(int key) {
        Node* z;
        PTR_ASSIGN(z, root);
        while (z != nil && !COMPARE_EQ(z->key, key)) {
            if (COMPARE_KEYS(key, z->key)) PTR_ASSIGN(z, z->left);
            else PTR_ASSIGN(z, z->right);
        }
        if (z == nil) return;

        Node* y;
        PTR_ASSIGN(y, z);
        Node* x;
        Color yOriginalColor = y->color;
        if (z->left == nil) {
            PTR_ASSIGN(x, z->right);
            transplant(z, z->right);
        } else if (z->right == nil) {
            PTR_ASSIGN(x, z->left);
            transplant(z, z->left);
        } else {
            PTR_ASSIGN(y, minimum(z->right));
            yOriginalColor = y->color;
            PTR_ASSIGN(x, y->right);
            if (y->parent == z) PTR_ASSIGN(x->parent, y);
            else {
                transplant(y, y->right);
                PTR_ASSIGN(y->right, z->right);
                PTR_ASSIGN(y->right->parent, y);
            }
            transplant(z, y);
            PTR_ASSIGN(y->left, z->left);
            PTR_ASSIGN(y->left->parent, y);
            y->color = z->color;
        }
        delete z;
        if (yOriginalColor == BLACK) deleteFixup(x);
    }

    int height(Node* node) {
        if (node == nil) return -1;
        return 1 + max(height(node->left), height(node->right));
    }

    char* left_trace;
    char* right_trace;

    void print_BST(Node* root, int depth, char prefix) {
        if (root == nil) return;
        if (root->left != nil) print_BST(root->left, depth + 1, '/');
        if (prefix == '/') left_trace[depth - 1] = '|';
        if (prefix == '\\') right_trace[depth - 1] = ' ';
        if (depth == 0) printf("-");
        if (depth > 0) printf(" ");
        for (int i = 0; i < depth - 1; i++)
            if (left_trace[i] == '|' || right_trace[i] == '|') printf("| ");
            else printf("  ");
        if (depth > 0) printf("%c-", prefix);
        printf("[%d]\n", root->key);
        left_trace[depth] = ' ';
        if (root->right != nil) {
            right_trace[depth] = '|';
            print_BST(root->right, depth + 1, '\\');
        }
    }

    void print() {
        print_BST(root, 0, ' ');
    }

    int height() {
        return height(root);
    }
};

void runTest(vector<int> sizes, const string& filename, bool sortedInsert) {
    ofstream file(filename, ios::app);
    mt19937 rng(random_device{}());
    int trials = 5, times = 4;
    if (sortedInsert) {
        trials = 1;
        times = 20;
    }

    for (int n : sizes) {
        for (int t = 0; t < trials; ++t) {
            double h = 0, l = 0;
            vector<int> data(n);
            for (int i = 0; i < n; ++i) data[i] = i + 1;

            if (!sortedInsert) shuffle(data.begin(), data.end(), rng);

            vector<int> deleteOrder = data;
            shuffle(deleteOrder.begin(), deleteOrder.end(), rng);

            comparisons = 0;
            pointerChanges = 0;

            RB_BST tree;
            for (int key : data) {
                tree.insert(key);
                h += tree.height();
                l++;
            }
            for (int key : data) {
                tree.deleteKey(key);
                h += tree.height();
                l++;
            }

            for (int i = 0; i < times; i++)
                file << comparisons << " " << pointerChanges << " " << h / l << endl;
        }
    }
    file.close();
}

int main() {
    const vector<int> sizes = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    //runTest(sizes, "test1.txt", true);
    runTest(sizes, "test2.txt", false);
    return 0;
}