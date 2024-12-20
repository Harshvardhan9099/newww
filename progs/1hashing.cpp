#include <iostream>
#define MAX 10
using namespace std;

class HashTable {
private:
    string names[MAX];          // Array to store client names
    long long numbers[MAX];     // Array to store phone numbers

public:
    HashTable() {
        for (int i = 0; i < MAX; i++) {
            names[i] = "";      // Initialize all names to empty
            numbers[i] = 0;     // Initialize all phone numbers to 0
        }
    }

    int hash(string name) {
        int sum = 0;
        for (int i = 0; i < name.length(); i++) {
            sum += name[i];     // Add ASCII values of characters
        }
        return sum % MAX;       // Fit the hash value into the table size
    }

    void insert() {
        string name;
        long long number;

        cout << "Enter client name: ";
        cin >> name;
        cout << "Enter telephone number: ";
        cin >> number;

        int pos = hash(name);

        for (int i = 0; i < MAX; i++) {
            int index = (pos + i) % MAX;  // Linear probing
            if (names[index] == "") {    // Empty slot found
                names[index] = name;
                numbers[index] = number;
                cout << "Inserted at position " << index << endl;
                return;
            }
        }

        cout << "Hash table is full!" << endl;  // No space available
    }

    void search() {
        string name;
        cout << "Enter client name to search: ";
        cin >> name;

        int pos = hash(name);

        for (int i = 0; i < MAX; i++) {
            int index = (pos + i) % MAX;  // Linear probing
            if (names[index] == name) {  // Match found
                cout << "Found at position " << index << ": " << numbers[index] << endl;
                return;
            }
            if (names[index] == "") {    // Empty slot, stop searching
                break;
            }
        }

        cout << "Client not found." << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < MAX; i++) {
            if (names[i] == "") {
                cout << i << ": [Empty]" << endl;
            } else {
                cout << i << ": " << names[i] << " - " << numbers[i] << endl;
            }
        }
    }
};

int main() {
    HashTable table;
    int choice;

    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            table.insert();
            break;
        case 2:
            table.search();
            break;
        case 3:
            table.display();
            break;
        case 4:
            cout << "Exiting. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

