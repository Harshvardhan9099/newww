#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void addstudent() {
    ofstream f("db.txt", ios::app);
    string rn, name, div, add;
    cout << "Enter Student Roll No: ";
    cin >> rn;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Student Div: ";
    cin >> div;
    cout << "Enter Student Address: ";
    cin >> add;

    f << left << setw(20) << rn << setw(20) << name << setw(20) << div << setw(20) << add << endl;
    cout << "Student Added Successfully.\n";
}

void deletestudent() {
    ifstream f("db.txt");
    string line, rn, FileData;
    cout << "Enter Student Roll No to delete: ";
    cin >> rn;

    while (getline(f, line)) {
        if (line.find(rn) == string::npos) {
            FileData += line + "\n";
        }
    }
    f.close();

    ofstream f1("db.txt", ios::out);
    f1 << FileData;
}

void searchstudent() {
    ifstream f("db.txt");
    string line, rn;
    bool found = false;
    cout << "Enter Student Roll No to Search: ";
    cin >> rn;

    while (getline(f, line)) {
        if (line.find(rn) != string::npos) {
            cout << "Student Details:\n" << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student Doesn't Exist.\n";
    }
}

void printstudent() {
    ifstream f("db.txt");
    string line;
    cout << "\nPrinting file data...\n";
    while (getline(f, line)) {
        cout << line << endl;
    }
    f.close();
}

int main() {
    ofstream f("db.txt", ios::out);
    f << left << setw(20) << "Roll No" << setw(20) << "Name" << setw(20) << "Division" << setw(20) << "Address" << endl;
    f.close();

    int ip;
    while (true) {
        cout << "\nEnter your choice\n1. Add Student\n2. Delete Student\n3. Search Student\n4. Print Data\n5. Exit\n...";
        cin >> ip;
        switch (ip) {
            case 1: addstudent(); break;
            case 2: deletestudent(); break;
            case 3: searchstudent(); break;
            case 4: printstudent(); break;
            case 5: return 0;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    }
}

