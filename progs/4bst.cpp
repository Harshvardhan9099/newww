#include<iostream>
using namespace std;

class Bstnode {
public:
    int data;              // The data stored in the node
    Bstnode* left;         // Pointer to the left child
    Bstnode* right;        // Pointer to the right child
    
    // Constructor to initialize a node with a given value
    Bstnode(int val) {
        data = val;
        left = right = NULL;
    }
};

class Btree {
public:
    Bstnode* root;        // Root of the tree
    
    // Constructor to initialize an empty tree
    Btree() {
        root = NULL;
    }

    // Function to insert a value into the tree
    Bstnode* insert(Bstnode* node, int val) {
        // If the current node is NULL, create a new node and return it
        if (node == NULL) {
            return new Bstnode(val);
        }

        // If the value is smaller, insert it into the left subtree
        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        // If the value is greater or equal, insert it into the right subtree
        else {
            node->right = insert(node->right, val);
        }

        // Return the (possibly modified) node
        return node;
    }

    // Function to display the tree using different traversals
    void display() {
        cout << "--- Inorder Traversal ---" << endl;
        inorder(root);
        cout << endl;

        cout << "--- Preorder Traversal ---" << endl;
        preorder(root);
        cout << endl;

        cout << "--- Postorder Traversal ---" << endl;
        postorder(root);
        cout << endl;
    }

    // Function to perform inorder traversal (Left, Root, Right)
    void inorder(Bstnode* node) {
        if (node != NULL) {
            inorder(node->left);  // Traverse the left subtree
            cout << node->data << " ";  // Print the root
            inorder(node->right);  // Traverse the right subtree
        }
    }

    // Function to perform preorder traversal (Root, Left, Right)
    void preorder(Bstnode* node) {
        if (node != NULL) {
            cout << node->data << " ";  // Print the root
            preorder(node->left);  // Traverse the left subtree
            preorder(node->right);  // Traverse the right subtree
        }
    }

    // Function to perform postorder traversal (Left, Right, Root)
    void postorder(Bstnode* node) {
        if (node != NULL) {
            postorder(node->left);  // Traverse the left subtree
            postorder(node->right);  // Traverse the right subtree
            cout << node->data << " ";  // Print the root
        }
    }

    // Function to search for a value in the tree
    void search(Bstnode* node, int val) {
        if (node == NULL) {
            cout << "Element not found!" << endl;  // Value not found
            return;
        }

        // If the value matches the current node's data
        if (node->data == val) {
            cout << ":-- Record Found --:" << endl;
            return;
        }
        // If the value is smaller, search in the left subtree
        else if (val < node->data) {
            search(node->left, val);
        }
        // If the value is larger, search in the right subtree
        else {
            search(node->right, val);
        }
    }

    // Function to find and display the minimum value in the tree
    void minvalue(Bstnode* node) {
        if (node == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        // Traverse left until we find the leftmost node (minimum value)
        while (node->left != NULL) {
            node = node->left;
        }
        cout << "Minimum value = " << node->data << endl;
    }

    // Function to mirror the tree (swap left and right children)
    void mirror(Bstnode* node) {
        if (node == NULL) {
            return;  // Base case: if the node is NULL, do nothing
        }

        // Recursively mirror the left and right subtrees
        mirror(node->left);
        mirror(node->right);

        // Swap the left and right child pointers
        Bstnode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

    // Function to calculate the depth of the tree
    int depth(Bstnode* node) {
        if (node == NULL) {
            return 0;  // The depth of an empty tree is 0
        }
        // Calculate the depth of the left and right subtrees, and return the greater depth + 1
        return max(depth(node->left), depth(node->right)) + 1;
    }
};

int main() {
    Btree tree;  // Create an empty tree
    int n, value;

    cout << "Enter the number of elements to insert: ";
    cin >> n;

    // Insert values into the tree
    for (int i = 0; i < n; i++) {
        cout << "Enter a value: ";
        cin >> value;
        tree.root = tree.insert(tree.root, value);  // Insert each value into the tree
    }

    // Display the tree using different traversals
    tree.display();

    // Search for a specific value in the tree
    cout << "Enter the element to search: ";
    cin >> value;
    tree.search(tree.root, value);

    // Display the minimum value in the tree
    tree.minvalue(tree.root);

    // Mirror the tree and display the inorder traversal of the mirrored tree
    cout << "Mirror image of the tree (Inorder traversal):" << endl;
    tree.mirror(tree.root);
    tree.inorder(tree.root);
    cout << endl;

    // Display the depth of the tree
    cout << "Depth of the tree: " << tree.depth(tree.root) << endl;

    return 0;
}

