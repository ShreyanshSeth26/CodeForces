#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1), b(m+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }

        vector<int> L(n+1, 0);
        for (int i = 1; i <= n; i++) {
            L[i] = L[i-1];
            if (L[i] < m && a[i] >= b[L[i]+1]) {
                L[i]++;
            }
        }
        if (L[n] == m) {
            cout << 0 << "\n";
            continue;
        }

        vector<int> a_rev(n+1), b_rev(m+1);
        for (int i = 1; i <= n; i++) {
            a_rev[i] = a[n - i + 1];
        }
        for (int i = 1; i <= m; i++) {
            b_rev[i] = b[m - i + 1];
        }
        vector<int> R_rev(n+1, 0);
        for (int i = 1; i <= n; i++) {
            R_rev[i] = R_rev[i-1];
            if (R_rev[i] < m && a_rev[i] >= b_rev[R_rev[i]+1]) {
                R_rev[i]++;
            }
        }

        vector<int> diff(m+2, 0);
        for (int t = 0; t <= n; t++) {
            int prefixMatched = L[t];
            int suffixMatched = R_rev[n - t];
            int lo = m - suffixMatched;
            int hi = prefixMatched + 1;
            if (lo < 1) lo = 1;
            if (hi > m) hi = m;
            if (lo <= hi) {
                diff[lo]++;
                diff[hi+1]--;
            }
        }
        for (int i = 1; i <= m; i++) {
            diff[i] += diff[i-1];
        }
        int answer = INT_MAX;
        for (int pos = 1; pos <= m; pos++) {
            if (diff[pos] > 0) {
                answer = min(answer, b[pos]);
            }
        }
        if (answer == INT_MAX) {
            cout << -1 << "\n";
        } else {
            cout << answer << "\n";
        }
    }

    return 0;
}
