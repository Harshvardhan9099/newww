#include <iostream>
using namespace std;

class Office {
    int n;
    int cost[10][10];        // Cost matrix
    string officeNames[10];  // Office names

public:
    void input();
    void display() const;
    void Prims() const;
};

void Office::input() {
    cout << "\nEnter the number of offices: ";
    cin >> n;

    cout << "\nEnter the names of the offices: ";
    for (int i = 0; i < n; ++i) {
        cin >> officeNames[i];
    }

    cout << "\nEnter the cost to connect the offices: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << "Enter the cost to connect " << officeNames[i] << " and " << officeNames[j] << ": ";
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];  // Symmetric cost matrix
        }
    }
}

void Office::display() const {
    cout << "\nCost matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << cost[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Office::Prims() const {
    bool visited[10] = {false};
    int minCost = 0, edgeCount = 0;
    visited[0] = true;
    cout << "\nMinimum spanning tree: " << officeNames[0] << " -> ";

    while (edgeCount < n - 1) {
        int minEdge = 10000, u = -1, v = -1;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                for (int j = 0; j < n; ++j) {
                    if (!visited[j] && cost[i][j] && cost[i][j] < minEdge) {
                        minEdge = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = true;
        cout << officeNames[v] << " -> ";
        minCost += minEdge;
        edgeCount++;
    }

    cout << "\nMinimum cost: " << minCost << "\n";
}

int main() {
    Office o1;
    int choice;

    do {
        cout << "\n\nMINIMUM SPANNING TREE";
        cout << "\n1. Input data";
        cout << "\n2. Display data";
        cout << "\n3. Calculate minimum cost";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            o1.input();
            break;
        case 2:
            o1.display();
            break;
        case 3:
            o1.Prims();
            break;
        case 4:
            cout << "Exit\n";
            break;
        }
    } while (choice != 4);

    return 0;
}

