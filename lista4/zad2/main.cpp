#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

long long comparisons = 0;
long long pointerChanges = 0;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        ++comparisons;
        if (!node) {
            ++pointerChanges;
            return new Node(key);
        }
        ++comparisons;
        if (key < node->key) {
            node->left = insert(node->left, key);
            ++pointerChanges;
        } else {
            node->right = insert(node->right, key);
            ++pointerChanges;
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            ++comparisons;
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return nullptr;
        ++comparisons;
        if (key < node->key) {
            node->left = deleteNode(node->left, key);
            ++pointerChanges;
        } else if (key > node->key) {
            ++comparisons;
            node->right = deleteNode(node->right, key);
            ++pointerChanges;
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                ++pointerChanges;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                ++pointerChanges;
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
            return -1;
        return 1 + max(height(node->left), height(node->right));
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    int height() {
        return height(root);
    }
};

void runTest(vector<int> sizes, const string& filename, bool sortedInsert) {
    ofstream file(filename, ios::app);
    mt19937 rng(random_device{}());
    int trials=20,times=1;
    if(sortedInsert || true)
    {
        trials=1;
        times=20;
    }

    for (int n : sizes) {
        for (int t = 0; t < trials; ++t) {
            double h=0,l=0;
            vector<int> data(n);
            for (int i = 0; i < n; ++i)
                data[i] = i + 1;

            if (!sortedInsert)
                shuffle(data.begin(), data.end(), rng);

            vector<int> deleteOrder = data;
            shuffle(deleteOrder.begin(), deleteOrder.end(), rng);

            comparisons = 0;
            pointerChanges = 0;

            BST tree;
            for (int key : data) {
                tree.insert(key);
                h+=tree.height();
                l++;
            }
            for (int key : data) {
                tree.deleteKey(key);
                h+=tree.height();
                l++;
            }
            
            for(int i=0;i<times;i++)
                file << comparisons << " " << pointerChanges << " " << h/l << endl;
        }
    }
    file.close();
}

int main() {
    const vector<int> sizes = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    const int trials = 20;

    runTest(sizes, "test1.txt", true);
    runTest(sizes, "test2.txt", false);

    return 0;
}