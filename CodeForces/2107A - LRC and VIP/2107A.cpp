#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> prefix(n+1, 0), suffix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = gcd(prefix[i], a[i]);
        }
        for (int i = n-1; i >= 0; i--) {
            suffix[i] = gcd(suffix[i+1], a[i]);
        }

        vector<int> assignment(n, 2);
        bool found = false;
        for (int i = 0; i < n; i++) {
            int g_excl = gcd(prefix[i], suffix[i+1]);
            if (g_excl != a[i]) {
                assignment[i] = 1;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) {
                cout << assignment[i] << (i + 1 < n ? ' ' : '\n');
            }
        }
    }

    return 0;
}
