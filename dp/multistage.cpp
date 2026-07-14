#include <bits/stdc++.h>
using namespace std;

#define INF 999999

int main() {
    int n = 8; // number of vertices

    // adjacency matrix (1-based indexing)
    int c[9][9] = {0};

    // Fill edges from your diagram
    c[1][2] = 2;  c[1][3] = 1;  c[1][4] = 3;
    c[2][5] = 2;  c[2][6] = 3;
    c[3][5] = 6;  c[3][6] = 7;  c[3][8] = 4;
    c[4][6] = 8;  c[4][7] = 9;
    c[5][8] = 6;
    c[6][8] = 4;
    c[7][8] = 5;

    int cost[9], d[9];

    // sink cost = 0
    cost[n] = 0;

    // compute backwards
    for (int i = n - 1; i >= 1; i--) {
        int minCost = INF;
        int nextVertex = -1;
        for (int j = i + 1; j <= n; j++) {
            if (c[i][j] != 0) {
                if (c[i][j] + cost[j] < minCost) {
                    minCost = c[i][j] + cost[j];
                    nextVertex = j;
                }
            }
        }
        cost[i] = minCost;
        d[i] = nextVertex;
    }

    cout << "Minimum cost from 1 to " << n << " = " << cost[1] << endl;

    cout << "Path: ";
    int v = 1;
    cout << v;
    while (v != n) {
        v = d[v];
        cout << " -> " << v;
    }
    cout << endl;

    return 0;
}
