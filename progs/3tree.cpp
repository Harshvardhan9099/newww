#include <iostream>
#include <cstring>
using namespace std;

// Node structure for each item (book, chapter, section, subsection)
class Node {
public:
    char name[20];   // Name of the node (book, chapter, section, subsection)
    Node* next;      // Pointer to the next sibling node (same level)
    Node* down;      // Pointer to the first child node (next level)
    
    Node() {
        next = down = NULL; // Use NULL instead of nullptr
    }
};

// Generalized Linked List (Tree) structure for Book
class GLL {
public:
    Node* head = NULL; // Head node to represent the book

    // Function to create a new node
    Node* createNode() {
        Node* newNode = new Node;
        cout << "Enter name: ";
        cin >> newNode->name;
        return newNode;
    }

    // Function to insert a book (Root node)
    void insertBook() {
        if (head == NULL) {
            head = createNode();
        } else {
            cout << "Book already exists.\n";
        }
    }

    // Function to insert a chapter
    void insertChapter() {
        if (head == NULL) {
            cout << "No book exists.\n";
            return;
        }

        cout << "Enter chapter name: ";
        Node* chapter = createNode();
        if (head->down == NULL) {
            head->down = chapter;  // First chapter under the book
        } else {
            Node* temp = head->down;
            while (temp->next != NULL) {
                temp = temp->next;  // Traverse to the last chapter
            }
            temp->next = chapter; // Insert new chapter as sibling
        }
    }

    // Function to insert a section under a chapter
    void insertSection() {
        if (head == NULL) {
            cout << "No book exists.\n";
            return;
        }

        char chapterName[20];
        cout << "Enter chapter name to insert section: ";
        cin >> chapterName;

        Node* temp = head->down;
        while (temp != NULL) {
            if (strcmp(temp->name, chapterName) == 0) {
                Node* section = createNode();
                if (temp->down == NULL) {
                    temp->down = section;  // First section under the chapter
                } else {
                    Node* secTemp = temp->down;
                    while (secTemp->next != NULL) {
                        secTemp = secTemp->next;  // Traverse to last section
                    }
                    secTemp->next = section;  // Insert new section
                }
                return;
            }
            temp = temp->next;  // Go to next chapter
        }
        cout << "Chapter not found.\n";
    }

    // Function to insert a subsection under a section
    void insertSubsection() {
        if (head == NULL) {
            cout << "No book exists.\n";
            return;
        }

        char chapterName[20], sectionName[20];
        cout << "Enter chapter name to insert subsection: ";
        cin >> chapterName;
        cout << "Enter section name to insert subsection: ";
        cin >> sectionName;

        Node* temp = head->down;
        while (temp != NULL) {
            if (strcmp(temp->name, chapterName) == 0) {
                Node* secTemp = temp->down;
                while (secTemp != NULL) {
                    if (strcmp(secTemp->name, sectionName) == 0) {
                        Node* subsection = createNode();
                        if (secTemp->down == NULL) {
                            secTemp->down = subsection;  // First subsection under the section
                        } else {
                            Node* subTemp = secTemp->down;
                            while (subTemp->next != NULL) {
                                subTemp = subTemp->next;  // Traverse to last subsection
                            }
                            subTemp->next = subsection;  // Insert new subsection
                        }
                        return;
                    }
                    secTemp = secTemp->next;  // Go to next section
                }
                cout << "Section not found.\n";
                return;
            }
            temp = temp->next;  // Go to next chapter
        }
        cout << "Chapter not found.\n";
    }

    // Function to display the book structure
    void display(Node* node) {
        if (node == NULL) return;

        cout << node->name << endl;
        display(node->down); // Display children (subsections, sections, chapters)
        display(node->next); // Display siblings (next chapter, section, etc.)
    }

    // Function to initiate display from the root node (book)
    void displayBook() {
        if (head == NULL) {
            cout << "No book exists.\n";
        } else {
            cout << "Book: " << head->name << endl;
            display(head->down);  // Start with the chapters
        }
    }
};

// Main function to test the tree structure
int main() {
    GLL gll;  // Create the Generalized Linked List (GLL) object
    int choice;

    do {
        cout << "\n1. Insert Book\n";
        cout << "2. Insert Chapter\n";
        cout << "3. Insert Section\n";
        cout << "4. Insert Subsection\n";
        cout << "5. Display Book Structure\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: gll.insertBook(); break;
            case 2: gll.insertChapter(); break;
            case 3: gll.insertSection(); break;
            case 4: gll.insertSubsection(); break;
            case 5: gll.displayBook(); break;
            case 6: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}

