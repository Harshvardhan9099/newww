#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;  // Use NULL instead of nullptr for C++98
    }
};

class TBT {
public:
    Node *root;

    TBT() {
        root = NULL;  // Use NULL instead of nullptr for C++98
    }

    void insert(int x) {
        Node *newNode = new Node(x);
        if (root == NULL) {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = NULL;
        while (current != NULL) {
            parent = current;
            if (x < current->data)
                current = current->left;
            else if (x > current->data)
                current = current->right;
            else {
                cout << "Data is already present!" << endl;
                return;
            }
        }

        if (x < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    void inorder() {
        inorderHelper(root);
        cout << "\n";
    }

    void preorder() {
        preorderHelper(root);
        cout << "\n";
    }

private:
    void inorderHelper(Node* node) {
        if (node == NULL) {
            return;
        }
        inorderHelper(node->left);  // Traverse left subtree
        cout << node->data << " ";   // Visit the root
        inorderHelper(node->right);  // Traverse right subtree
    }

    void preorderHelper(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";  // Visit the root
        preorderHelper(node->left); // Traverse left subtree
        preorderHelper(node->right); // Traverse right subtree
    }
};

int main() {
    TBT tree;
    char ch;
    do {
        int data;
        cout << "Enter data: ";
        cin >> data;
        tree.insert(data);

        cout << "Do you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y');

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    return 0;
}

