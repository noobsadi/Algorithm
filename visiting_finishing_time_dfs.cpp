#include<bits/stdc++.h>
using namespace std;

int timer=1;


void DFS(int node, vector<int>adj[], vector<bool>&visited, vector<int>&visitingTime, vector<int>&finishingTime){

    visited[node]=1;
   visitingTime[node]=timer++;

    for(int j=0;j<adj[node].size();j++){

        if(!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited, visitingTime, finishingTime);
    }
    finishingTime[node]=timer++;
}

int main(){
    int n, e;
    cin >> n >> e;

    vector<int>visitingTime(n), finishingTime(n);
    vector<int>adj[n];
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(n, 0);
    for (int i=0;i<n;i++){
        if(!visited[i]){
             DFS(i, adj, visited, visitingTime,finishingTime);

        }
    }
    
   
    for(int i=0;i<n;i++)
        cout <<i<<":" <<visitingTime[i] << " " << finishingTime[i] << endl;
    return 0;
}