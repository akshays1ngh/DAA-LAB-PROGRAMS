#include <iostream>

using namespace std;

int main() {
    int n, k;
    cout << "Enter the number of modules, that is, dependent and independent combined: ";
    cin >> n;
    cout << "Enter the number of teams: ";
    cin >> k;

    // Initialize adjacency matrix and indegree array
    //vector<vector<int>> adj_mat(n, vector<int>(n, 0));
    int adj_mat[n][n];
    for(int i=0;<n;i++)
        for(int j=0;j<n;j++)
            adj_mat[i][j]=0;
    int indegree[n]= {0};

    // Input the dependencies
    for (int i = 0; i < k; i++) {
        int team_size;
        cout << "Enter the size of team " << i+1 << ": ";
        cin >> team_size;

        int last_module = -1;
        for (int j = 0; j < team_size; j++) {
            int module;
            cout << "Enter the module number: ";
            cin >> module;

            if (last_module != -1) { // Check for task dependency
                adj_mat[last_module][module] = 1;
                indegree[module]++;
            }
            last_module = module;
        }
    }

    // Topological sorting using Kahn's algorithm
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    cout << "Task scheduling order is: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < n; i++) {
            if (adj_mat[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
    cout << endl;

    return 0;
}

