#include <iostream>
#include <vector>
using namespace std;

void transitiveClosure(vector<vector<int>>& graph, int n) {
    // Initialize the transitive closure matrix
    vector<vector<int>> transitiveClosure(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transitiveClosure[i][j] = graph[i][j];
        }
    }

    // Update the transitive closure matrix using Warshall's algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    cout << "Transitive closure matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << transitiveClosure[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges:\n";
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }
    transitiveClosure(graph, n);
    return 0;
}
