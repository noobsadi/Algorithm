#include <bits/stdc++.h>
using namespace std;

int main() {
    

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        if (n == 1) {
            cout << 1 << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                cout << 2 << (i + 1 == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}
