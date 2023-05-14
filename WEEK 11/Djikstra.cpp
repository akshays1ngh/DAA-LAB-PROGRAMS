#include<bits/stdc++.h>
using namespace std;
#define V 4
int mindist(int vis[], int dist[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!vis[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void djikstra(int graph[][V],int src){
    int dist[V],vis[V];
    
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        vis[i]=0;
    }
    
    dist[src]=0;
    for(int c=0;c<V-1;c++){
        int u=mindist(vis,dist);
        
        vis[u]=1;
        
        for(int node=0;node<V;node++){
            if(!vis[node] && graph[u][node] && dist[u]!=INT_MAX && (graph[u][node]+dist[u])<dist[node]){
                dist[node]=graph[u][node]+dist[u];
                
            }
        }
    }
         cout << "Vertex \t Distance from Source\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << endl;
    }
}
int main(){
    int graph[V][V];
    cout<<"Enter adj matrix: "<<endl;
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin>>graph[i][j];
    cout << "Enter source: "<<endl;
    int src;
    cin>>src;
    djikstra(graph,src);
    return 0;
}



