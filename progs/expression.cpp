#include <iostream>
using namespace std;

// Define a tree node structure
struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char val) : value(val), left(NULL), right(NULL) {}
};

// Define a simple stack structure for nodes
struct Stack {
    Node* data[100];  // Fixed-size array for simplicity
    int top;

    Stack() : top(-1) {}

    void push(Node* node) {
        if (top < 99) {
            data[++top] = node;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    Node* pop() {
        if (top >= 0) {
            return data[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return NULL;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to construct an expression tree from a prefix expression
Node* constructExpressionTree(const string& prefix) {
    Stack stack;

    // Traverse the prefix expression from right to left
    for (int i = prefix.size() - 1; i >= 0; --i) {
        char symbol = prefix[i];

        if (isalnum(symbol)) { // If it's an operand
            stack.push(new Node(symbol));
        } else { // If it's an operator
            Node* node = new Node(symbol);
            node->left = stack.pop();
            node->right = stack.pop();
            stack.push(node);
        }
    }

    return stack.pop(); // The root of the expression tree
}

// Non-recursive postorder traversal of the tree
void postOrderTraversal(Node* root) {
    if (!root) return;

    Stack stack1, stack2;
    stack1.push(root);

    while (!stack1.isEmpty()) {
        Node* node = stack1.pop();
        stack2.push(node);

        if (node->left) stack1.push(node->left);
        if (node->right) stack1.push(node->right);
    }

    // Print nodes in postorder
    while (!stack2.isEmpty()) {
        cout << stack2.pop()->value << " ";
    }
}

// Function to delete the entire tree
void deleteTree(Node* root) {
    if (!root) return;

    Stack stack;
    stack.push(root);

    while (!stack.isEmpty()) {
        Node* node = stack.pop();

        if (node->left) stack.push(node->left);
        if (node->right) stack.push(node->right);

        delete node; // Free memory
    }
}

// Driver code
int main() {
    string prefix = "+--a*bc/def";

    // Step 1: Construct the expression tree
    Node* root = constructExpressionTree(prefix);

    // Step 2: Perform non-recursive postorder traversal
    cout << "Postorder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Step 3: Delete the tree
    deleteTree(root);

    return 0;
}

