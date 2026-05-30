#include<bits/stdc++.h>
using namespace std;


void DFS1(int node, vector<int>adj[], vector<bool>&visited, stack<int>&st){
    visited[node] = true;
    
    for(int neighbor : adj[node]){
        if(!visited[neighbor])
            DFS1(neighbor, adj, visited, st);
    }
    
    st.push(node);  
}


void DFS2(int node, vector<int>revAdj[], vector<bool>&visited, vector<int>&component){
    visited[node] = true;
    component.push_back(node);
    
    for(int neighbor : revAdj[node]){
        if(!visited[neighbor])
            DFS2(neighbor, revAdj, visited, component);
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
    }
    
    
    stack<int>st;
    vector<bool>visited(n, false);
    
    for(int i = 0; i < n; i++){
        if(!visited[i])
            DFS1(i, adj, visited, st);
    }
    
    
    vector<int>revAdj[n];
    for(int u = 0; u < n; u++){
        for(int v : adj[u]){
            revAdj[v].push_back(u);  
        }
    }
    
    
    fill(visited.begin(), visited.end(), false);
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        if(!visited[node]){
            vector<int>component;
            DFS2(node, revAdj, visited, component);
            
           
            for(int v : component)
                cout << v << " ";
            cout << "\n";
        }
    }
    
    return 0;
}