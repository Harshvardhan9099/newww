#include<iostream>
#include<string>
using namespace std;

class Word {
public:
    string word = "";  // Default empty string for word
    string meaning = "";  // Default empty string for meaning

    void printWord() {
        cout << word << "\t" << meaning << endl;
    }
};

class Dictionary {
private:
    Word words[26];
    bool replaceOnCollision;

public:
    void create() {
        cout << "Enter 1 for hashing with replacement, 0 for hashing without replacement: ";
        cin >> replaceOnCollision;
    }

    int hash(char c) {
        if (c >= 'a') return c - 'a';  // Handle lowercase letters
        return c - 'A';  // Handle uppercase letters
    }

    void addWord() {
        string w, m;
        cout << "Enter word: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, w);
        cout << "Enter meaning: ";
        getline(cin, m);

        int index = hash(w[0]);

        if (replaceOnCollision && words[index].word != "") {
            cout << "Replacing existing word at index " << index << endl;
            words[index] = Word();
            words[index].word = w;
            words[index].meaning = m;
            return;
        }

        int originalIndex = index;
        while (words[index].word != "") {
            index = (index + 1) % 26;
            if (index == originalIndex) {
                cout << "Dictionary is full. Cannot add new word." << endl;
                return;
            }
        }

        words[index] = Word();
        words[index].word = w;
        words[index].meaning = m;
        cout << "Word added successfully!" << endl;
    }

    void searchWord() {
        string w;
        cout << "Enter word to search: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, w);

        int index = hash(w[0]);
        int originalIndex = index;

        while (words[index].word != "") {
            if (words[index].word == w) {
                cout << "Meaning: " << words[index].meaning << endl;
                return;
            }
            index = (index + 1) % 26;
            if (index == originalIndex) break;  // Prevent infinite loop
        }

        cout << "Word not found!" << endl;
    }

    void deleteWord() {
        string w;
        cout << "Enter word to delete: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, w);

        int index = hash(w[0]);
        int originalIndex = index;

        while (words[index].word != "") {
            if (words[index].word == w) {
                words[index] = Word();  // Clear the word and meaning
                cout << "Word deleted successfully!" << endl;
                return;
            }
            index = (index + 1) % 26;
            if (index == originalIndex) break;  // Prevent infinite loop
        }

        cout << "Word not found!" << endl;
    }

    void printTable() {
        cout << "Dictionary Contents:" << endl;
        for (int i = 0; i < 26; i++) {
            if (words[i].word != "") {
                cout << i << ": ";
                words[i].printWord();
            }
        }
    }
};

int main() {
    Dictionary dict;
    int option;

    dict.create();

    do {
        cout << "\nOptions:\n";
        cout << "1. Add a new word\n";
        cout << "2. Search for a word\n";
        cout << "3. Delete a word\n";
        cout << "4. Print all words\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1: dict.addWord(); break;
            case 2: dict.searchWord(); break;
            case 3: dict.deleteWord(); break;
            case 4: dict.printTable(); break;
            case 5: break;
            default: cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 5);

    return 0;
}

