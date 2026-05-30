#include<bits/stdc++.h>
using namespace std;


int timer = 0;

void findBridges(int u, int parent, vector<int>adj[], 
                 vector<int>&visitTime, vector<int>&low, 
                 vector<bool>&visited){
    visited[u] = 1;
    visitTime[u] = low[u] = timer++;

    for(int v : adj[u]){
        if(v == parent) continue;  // skip parent edge

        if(visited[v]){
            low[u] = min(low[u], visitTime[v]);  // back edge
        }
        else{
            findBridges(v, u, adj, visitTime, low, visited);
            low[u] = min(low[u], low[v]);

            // Bridge condition: v cannot reach above u
            if(low[v] > visitTime[u]){
                cout << u << " " << v << endl;
            }
        }
    }
}


int main(){
    int n, e;
    cin >> n >> e;
    vector<int>adj[n];
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(n, 0);
    vector<int>visitTime(n, 0);
    vector<int>low(n, 0);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            findBridges(i, -1, adj, visitTime, low, visited);
        }
    }
return 0;
}