#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree() {
        root = nullptr;
    }

    void add(int value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else {
            Node* current = root;
            while (true) {
                if (value < current->value) {
                    if (current->left == nullptr) {
                        current->left = new Node(value);
                        break;
                    }
                    else {
                        current = current->left;
                    }
                }
                else {
                    if (current->right == nullptr) {
                        current->right = new Node(value);
                        break;
                    }
                    else {
                        current = current->right;
                    }
                }
            }
        }
    }

    void print() {
        if (root == nullptr) {
            cout << "Tree = 0" << endl;
            return;
        }

        printSimple(root);
        cout << endl;
    }

    void printSimple(Node* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        printSimple(node->left);    
        printSimple(node->right);  
    }
};

int main() {
    Tree tree;

    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);

    cout << "Tree element: ";
    tree.print();
}
