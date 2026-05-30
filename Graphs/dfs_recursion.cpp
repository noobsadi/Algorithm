#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int>adj[], vector<bool>&visited, vector<int>&ans){

    visited[node]=1;
    ans.push_back(node);

    for(int j=0;j<adj[node].size();j++){

        if(!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited, ans);
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
    vector<int>ans;
    DFS(0, adj, visited, ans);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}