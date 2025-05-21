#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> p(n);

        if (x == n) {
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        } else {
            int idx = 0;
            for (int v = 0; v < x; v++) {
                p[idx++] = v;
            }
            for (int v = x + 1; v < n; v++) {
                p[idx++] = v;
            }
            p[idx++] = x;
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
