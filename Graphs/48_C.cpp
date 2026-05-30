#include<bits/stdc++.h>
using namespace std;

int timer = 0;

void findArticulationPoints(int u, int parent, vector<int>adj[], 
                            vector<int>&visitTime, vector<int>&low, 
                            vector<bool>&visited, set<int>&artPoints){
    visited[u] = true;
    visitTime[u] = low[u] = timer++;
    int children = 0;  

    for(int v : adj[u]){
        if(v == parent) continue; 

        if(visited[v]){
            
            low[u] = min(low[u], visitTime[v]);
        }
        else{
            
            children++;
            findArticulationPoints(v, u, adj, visitTime, low, visited, artPoints);
            low[u] = min(low[u], low[v]);

            
            if(parent != -1 && low[v] >= visitTime[u]){
                artPoints.insert(u);
            }
        }
    }

    
    if(parent == -1 && children > 1){
        artPoints.insert(u);
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    
    vector<int>adj[n];
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool>visited(n, false);
    vector<int>visitTime(n, 0);
    vector<int>low(n, 0);
    set<int>artPoints;  

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            findArticulationPoints(i, -1, adj, visitTime, low, visited, artPoints);
        }
    }

    
    for(int node : artPoints){
        cout << node << "\n";
    }

    return 0;
}