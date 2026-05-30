#include<bits/stdc++.h>
using namespace std;

bool DetectCycle(int node, int parent, vector<int>adj[], vector<bool>&visited){

    visited[node]=1;
    for(int j=0;j<adj[node].size();j++){
        if(adj[node][j]==parent)continue;
        if(visited[adj[node][j]]==1 )return true;

        if(DetectCycle(adj[node][j], node, adj, visited)) return true;
    }
    return false;
}

int main(){

    int nodes, edges;
    cin>>nodes>>edges;

    vector<int>adj[nodes];

    vector<bool>visited(nodes, 0);

    for(int i=0;i<edges;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
    if(DetectCycle(i, -1, adj, visited)){
        cout<<"Cycle detected"<<endl;
        return 0;
    }
    }
}
    
     cout<<"No cycle detected"<<endl;
    
return 0;

}