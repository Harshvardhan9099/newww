#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    char word[50], meaning[100];
    Node *left, *right;

    Node(const char w[], const char m[]) {
        strcpy(word, w);
        strcpy(meaning, m);
        left = right = NULL;
    }
};

class AVL {
private:
    Node *root;

    Node* insert(Node* node, const char word[], const char meaning[]);
    Node* deleteNode(Node* node, const char word[]);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* findMin(Node* node);
    int height(Node* node);
    void preorder(Node* node);

public:
    AVL() : root(NULL) {}
    void insert(const char word[], const char meaning[]) { root = insert(root, word, meaning); }
    void remove(const char word[]) { root = deleteNode(root, word); }
    void display() { preorder(root); }
};

int AVL::height(Node* node) {
    if (!node) return 0;
    return max(height(node->left), height(node->right)) + 1;
}

Node* AVL::rotateLeft(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}

Node* AVL::rotateRight(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

Node* AVL::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

Node* AVL::insert(Node* node, const char word[], const char meaning[]) {
    if (!node) return new Node(word, meaning);

    int cmp = strcmp(word, node->word);
    if (cmp < 0) node->left = insert(node->left, word, meaning);
    else if (cmp > 0) node->right = insert(node->right, word, meaning);
    else return node; // Duplicate word

    int balance = height(node->left) - height(node->right);
    if (balance > 1) {
        if (strcmp(word, node->left->word) < 0) return rotateRight(node); // LL
        node->left = rotateLeft(node->left); return rotateRight(node); // LR
    }
    if (balance < -1) {
        if (strcmp(word, node->right->word) > 0) return rotateLeft(node); // RR
        node->right = rotateRight(node->right); return rotateLeft(node); // RL
    }
    return node;
}

Node* AVL::deleteNode(Node* node, const char word[]) {
    if (!node) return node;

    int cmp = strcmp(word, node->word);
    if (cmp < 0) node->left = deleteNode(node->left, word);
    else if (cmp > 0) node->right = deleteNode(node->right, word);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        strcpy(node->word, temp->word);
        strcpy(node->meaning, temp->meaning);
        node->right = deleteNode(node->right, temp->word);
    }

    int balance = height(node->left) - height(node->right);
    if (balance > 1) {
        if (height(node->left->left) >= height(node->left->right)) return rotateRight(node); // LL
        node->left = rotateLeft(node->left); return rotateRight(node); // LR
    }
    if (balance < -1) {
        if (height(node->right->right) >= height(node->right->left)) return rotateLeft(node); // RR
        node->right = rotateRight(node->right); return rotateLeft(node); // RL
    }
    return node;
}

void AVL::preorder(Node* node) {
    if (!node) return;
    cout << node->word << " - " << node->meaning << endl;
    preorder(node->left);
    preorder(node->right);
}

int main() {
    AVL tree;
    char word[50], meaning[100];
    char choice;

    do {
        cout << "\nMenu: \n";
        cout << "1. Insert Word\n";
        cout << "2. Delete Word\n";
        cout << "3. Display Words (Pre-Order Traversal)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter the Word: ";
                cin >> word;
                cout << "Enter the Meaning: ";
                cin >> meaning;
                tree.insert(word, meaning);
                break;

            case '2':
                cout << "Enter the Word to Delete: ";
                cin >> word;
                tree.remove(word);
                break;

            case '3':
                cout << "\nWords in Pre-Order Traversal:\n";
                tree.display();
                break;

            case '4':
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}

