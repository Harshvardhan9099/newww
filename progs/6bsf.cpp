#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int cost[10][10], n, m;

void BFS(int start) {
    bool visited[10] = {false};
    queue<int> q;
    visited[start] = true;
    cout << "BFS Traversal: " << start << " ";

    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int j = 0; j < n; j++) {
            if (cost[v][j] && !visited[j]) {
                visited[j] = true;
                cout << j << " ";
                q.push(j);
            }
        }
    }
    cout << endl;
}

void DFS(int start) {
    bool visited[10] = {false};
    stack<int> s;
    visited[start] = true;
    cout << "DFS Traversal: " << start << " ";

    s.push(start);
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        for (int j = n-1; j >= 0; j--) {  // Iterate in reverse order for DFS
            if (cost[v][j] && !visited[j]) {
                visited[j] = true;
                cout << j << " ";
                s.push(j);
            }
        }
    }
    cout << endl;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    
    cout << "\nEnter the edges (u v) where u and v are 0-indexed:\n";
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        if (i < n && j < n) {  // Check that input is valid
            cost[i][j] = 1;
            cost[j][i] = 1;
        } else {
            cout << "Invalid edge between " << i << " and " << j << "\n";
        }
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    int start;
    cout << "Enter initial vertex for BFS: ";
    cin >> start;
    if (start >= 0 && start < n) {
        BFS(start);
    } else {
        cout << "Invalid vertex for BFS\n";
    }

    cout << "Enter initial vertex for DFS: ";
    cin >> start;
    if (start >= 0 && start < n) {
        DFS(start);
    } else {
        cout << "Invalid vertex for DFS\n";
    }

    return 0;
}

