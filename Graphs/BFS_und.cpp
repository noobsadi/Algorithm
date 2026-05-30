#include<bits/stdc++.h>
using namespace std;



vector<int> BFSGraph(int v, vector<int>AdjList[],int start){
    vector<bool> visited(v,0);
    queue<int> q;
    vector<int>ans;
    q.push(start);
    visited[start]=1;
    

    int node;
    while(!q.empty()){
        node=q.front();
        q.pop();
        ans.push_back(node);
      
    
    for(int j=0;j<AdjList[node].size();j++){
        if(!visited[AdjList[node][j]]){
            visited[AdjList[node][j]]=1;
            q.push(AdjList[node][j]);


        }
    }
}
  return ans;
} 





int main(){
    int vertex;
    cin>>vertex;

    vector<int> AdjList[vertex];
    AdjList[0] = {1,2};
    AdjList[1] = {0,5,7};
    AdjList[2] = {0,3,4};
    AdjList[3] = {2};
    AdjList[4] = {2};
    AdjList[5] = {1,6};
    AdjList[6] = {5,8};
    AdjList[7] = {1,8};
    AdjList[8] = {6,7};
    
   
    

    vector<int> result=BFSGraph(vertex, AdjList,0);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }


return 0;

}