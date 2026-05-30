#include<bits/stdc++.h>
using namespace std;

int timer = 0;

void DFS(int u, vector<pair<int,int>>adj[], vector<int>&visitTime, 
         vector<int>&finishTime, vector<bool>&visited, 
         map<pair<int,int>, char>&edgeType){
    
    visited[u] = true;
    visitTime[u] = timer++;
    
    for(auto edge : adj[u]){
        int v = edge.first;
        
        if(!visited[v]){
            // Tree Edge
            edgeType[{u, v}] = 'T';
            DFS(v, adj, visitTime, finishTime, visited, edgeType);
        }
        else if(finishTime[v] == 0){
            // Back Edge (v is visited but not finished - ancestor)
            edgeType[{u, v}] = 'B';
        }
        else if(visitTime[u] < visitTime[v]){
            // Forward Edge (u visited before v, v already finished)
            edgeType[{u, v}] = 'F';
        }
        else{
            // Cross Edge
            edgeType[{u, v}] = 'C';
        }
    }
    
    finishTime[u] = timer++;
}

int main(){
    int n, e;
    cin >> n >> e;
    
    vector<pair<int,int>>edges;  // Store all edges for sorted output
    vector<pair<int,int>>adj[n];  // Adjacency list with edge info
    
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back({v, i});  // Store neighbor and edge index
    }
    
    vector<int>visitTime(n, 0);
    vector<int>finishTime(n, 0);
    vector<bool>visited(n, false);
    map<pair<int,int>, char>edgeType;
    
    // Run DFS in increasing order of nodes
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(i, adj, visitTime, finishTime, visited, edgeType);
        }
    }
    
    // Sort edges and print
    sort(edges.begin(), edges.end());
    
    for(auto edge : edges){
        int u = edge.first;
        int v = edge.second;
        cout << u << " " << v << " (" << edgeType[{u, v}] << ")\n";
    }
    
    return 0;
}