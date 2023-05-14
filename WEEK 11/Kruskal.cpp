#include <iostream>
#include <algorithm>

using namespace std;

#define V 4

struct Edge {
    int src, dest, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    //return find(parent, parent[i]);
    return parent[i]=find(parent,parent[i]);
}

void unionRank(int parent[], int rank[], int u, int v) {
    int ulp_u = find(parent, u);
    int ulp_v = find(parent, v);

    if (rank[ulp_u] < rank[ulp_v]) {
        parent[ulp_u] = ulp_v;
    } else if (rank[ulp_u] > rank[ulp_v]) {
        parent[ulp_v] = ulp_u;
    } else {
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }
}

void kruskalMST(int graph[V][V]) {
    Edge edges[V*V];
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j]) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    sort(edges, edges+edgeCount, cmp);

    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstWeight = 0;
    cout << "Edge \tWeight\n";

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        int pu = find(parent, u);
        int pv = find(parent, v);

        if (pu != pv) {
            cout << u << " - " << v << "\t" << edges[i].weight << endl;
            mstWeight += edges[i].weight;
            unionRank(parent, rank, pu, pv);
        }
    }

    cout << "Minimum Cost Spanning Tree Weight: " << mstWeight << endl;
}

int main() {
    int graph[V][V];

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    kruskalMST(graph);

    return 0;
}
