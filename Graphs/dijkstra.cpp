#include<bits/stdc++.h>
using namespace std;


vector<int>dijkstra(int n, vector<vector<int>>adj[], int s){
    vector<bool>Explored(n,0);
    vector<int>dist(n, INT_MAX);
    dist[s]=0;

    int count=n;
    while(count--){
        int node=-1;
        int value=INT_MAX;

        for(int j=0;j<n;j++){
            if(!Explored[j] && value>dist[j]){
                node=j;
                value=dist[j];
            }

        }
        if(node==-1)break;
        Explored[node]=1;

        for(int i=0;i<adj[node].size();i++){
            int neighbour=adj[node][i][0];
            int weight=adj[node][i][1];
            if(!Explored[neighbour] && (dist[node]+weight<dist[neighbour])){
                dist[neighbour]=dist[node]+ weight;
            }
    }
}
    return dist;

}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    vector<vector<int>>adj[nodes];

    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});// for DAG we will not add this line adj[v].push_back(u);
       
    }
    vector<int>result=dijkstra(nodes, adj, 0);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

    return 0;
}