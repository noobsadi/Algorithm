#include <iostream>
#include <string>
using namespace std;

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    string X, Y;

    cout << "Enter First String: ";
    cin >> X;

    cout << "Enter Second String: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    int L[101][101];

    // Build DP Table
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            // Base Case
            if(i == 0 || j == 0)
            {
                L[i][j] = 0;
            }

            // Characters Match
            else if(X[i-1] == Y[j-1])
            {
                L[i][j] = L[i-1][j-1] + 1;
            }

            // Characters Don't Match
            else
            {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }

    cout << "\nLength of LCS = " << L[m][n] << endl;

    return 0;
}