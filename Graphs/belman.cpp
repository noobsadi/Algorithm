#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int nodes, vector<vector<int>> &edges, int source) {
    vector<int> dist(nodes, INT_MAX);

    dist[source] = 0;

    for (int i = 0; i < nodes - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check negative cycle
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Negative weight cycle detected" << endl;
            return {};
        }
    }

    return dist;
}

int main() {
    int nodes, edgeCount;
    cin >> nodes >> edgeCount;

    vector<vector<int>> edges;

    for (int i = 0; i < edgeCount; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    int source = 0;

    vector<int> result = bellmanFord(nodes, edges, source);

    for (int i = 0; i < result.size(); i++) {
        if (result[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << result[i] << endl;
    }

    return 0;
}