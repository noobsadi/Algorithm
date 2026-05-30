#include<bits/stdc++.h>
using namespace std;



void BFSGraph(int v, vector<int>AdjList[], int start,vector<int>&dist){
    vector<bool> visited(v,0);
    queue<int> q;
   
    q.push(start);
    visited[start]=1;
    dist[start]=0;



    int node;
    while(!q.empty()){
        node=q.front();
        q.pop();
       
      
    
    for(int j=0;j<AdjList[node].size();j++){
        if(!visited[AdjList[node][j]]){
            visited[AdjList[node][j]]=1;
            dist[AdjList[node][j]]=dist[node]+1;
            q.push(AdjList[node][j]);


        }
    }
}
  
} 





int main(){
    int n,e,target;
    cin>>n>>e>>target;

    vector<int> AdjList[n];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    
    
   
    vector<int> distance(n,-1);

    BFSGraph(n, AdjList,0,distance);
  

    for(int i=0;i<n;i++){
 
        cout<<i<<":"<<distance[i]<<endl;
        
    }


return 0;

}