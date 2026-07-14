#include <iostream>
using namespace std;

const int MAX = 105;
const int INF = 1000000000;

int dist[MAX][MAX];

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize distance matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // For directed graph
        dist[u][v] = min(dist[u][v], w);

        // Uncomment for undirected graph
        // dist[v][u] = min(dist[v][u], w);
    }

    // Floyd-Warshall Algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }

            }
        }
    }

    // Print shortest distance matrix
    cout << "Shortest Distance Matrix:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}