#include <iostream>
using namespace std;

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    // Profit array (1-indexed)
    int P[5] = {0, 1, 2, 5, 6};

    // Weight array (1-indexed)
    int wt[5] = {0, 2, 3, 4, 5};

    int n = 4;
    int m = 8;          // Knapsack Capacity

    int K[5][9];

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= m; w++)
        {
            // Case 1: Base case
            if(i == 0 || w == 0)
            {
                K[i][w] = 0;
            }

            // Case 2: Item can be included
            else if(wt[i] <= w)
            {
                K[i][w] = max(P[i] + K[i-1][w-wt[i]],
                              K[i-1][w]);
            }

            // Case 3: Item cannot be included
            else
            {
                K[i][w] = K[i-1][w];
            }
        }
    }

    cout << "Maximum Profit = " << K[n][m] << endl;

    cout << "\nDP Table:\n";

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= m; w++)
        {
            cout << K[i][w] << "\t";
        }
        cout << endl;
    }

    return 0;
}