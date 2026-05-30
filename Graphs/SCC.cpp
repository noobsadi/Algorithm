#include <bits/stdc++.h>
using namespace std;


void DFS1(int node,
          vector<vector<int>>& adj,
          vector<bool>& visited,
          stack<int>& st)
{
    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            DFS1(neighbor, adj, visited, st);
        }
    }

  
    st.push(node);
}


void DFS2(int node,
          vector<vector<int>>& revAdj,
          vector<bool>& visited,
          vector<int>& component)
{
    visited[node] = true;

    component.push_back(node);

    for (int neighbor : revAdj[node])
    {
        if (!visited[neighbor])
        {
            DFS2(neighbor, revAdj, visited, component);
        }
    }
}


void findSCC(int n, vector<vector<int>>& adj)
{
    stack<int> st;

    vector<bool> visited(n, false);


    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS1(i, adj, visited, st);
        }
    }

    vector<vector<int>> revAdj(n);

    for (int u = 0; u < n; u++)
    {
        for (int v : adj[u])
        {
            revAdj[v].push_back(u);
        }
    }

    
    fill(visited.begin(), visited.end(), false);

    int sccCount = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            vector<int> component;

            DFS2(node, revAdj, visited, component);

            cout << "SCC " << ++sccCount << ": ";

            for (int v : component)
            {
                cout << v << " ";
            }

            cout << endl;
        }
    }
}


int main()
{
    int n = 8;

    vector<vector<int>> adj(n);

  

   
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

 
    adj[2].push_back(3);

   
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(3);

   
    adj[5].push_back(6);

    
    adj[6].push_back(7);
    adj[7].push_back(6);

   
    findSCC(n, adj);

    return 0;
}