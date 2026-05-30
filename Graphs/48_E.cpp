#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int>adj[], vector<bool>&visited, stack<int>&s){

    visited[node]=1;

    for(int j=0;j<adj[node].size();j++){
        if(!visited[adj[node][j]]){
            DFS(adj[node][j], adj, visited, s);

        }

    }
    s.push(node);
}

vector<int> topoSort(int v, vector<int> adj[]){
    vector<bool>visited(v,0);
stack<int>s;
for(int i=0;i<v;i++){
    if(!visited[i]){
        DFS(i, adj, visited, s);
    }
}
vector<int>ans;
while(!s.empty()){
    ans.push_back(s.top());
    s.pop();
}
return ans;
}


int main(){

    int nodes, edges;
    cin>>nodes>>edges;

    vector<int>adj[nodes];

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
       
    }
    vector<int>result=topoSort(nodes, adj);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

    return 0;
    

}