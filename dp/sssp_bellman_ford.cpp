#include <iostream>
using namespace std;

const int MAX = 1005;
const int INF = 1000000000;

int u[MAX], v[MAX], w[MAX];
int dist[MAX];

int main() {

    int n, m;
    cin >> n >> m;

    // Input edges
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    int source;
    cin >> source;

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[source] = 0;

    // Bellman-Ford Algorithm
    for (int i = 1; i <= n - 1; i++) {

        for (int j = 0; j < m; j++) {

            if (dist[u[j]] != INF &&
                dist[u[j]] + w[j] < dist[v[j]]) {

                dist[v[j]] = dist[u[j]] + w[j];
            }

        }
    }

    // Check for negative weight cycle
    bool negativeCycle = false;

    for (int j = 0; j < m; j++) {

        if (dist[u[j]] != INF &&
            dist[u[j]] + w[j] < dist[v[j]]) {

            negativeCycle = true;
            break;
        }

    }

    if (negativeCycle) {
        cout << "Negative Weight Cycle Exists\n";
    }
    else {
        cout << "Shortest Distance from Source " << source << ":\n";

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INF)
                cout << i << " : INF\n";
            else
                cout << i << " : " << dist[i] << endl;

        }
    }

    return 0;
}