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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> prefix_max(n);
        prefix_max[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], a[i]);
        }

        vector<long long> suffix_sum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix_sum[i] = a[i] + suffix_sum[i + 1];
        }

        vector<long long> ans(n);
        for (int k = 1; k <= n; k++) {
            int L0 = n - k;
            long long M = suffix_sum[L0];
            if (L0 >= 1) {
                long long best_pref = prefix_max[L0 - 1];
                long long candidate = M - a[L0] + best_pref;
                ans[k - 1] = max(M, candidate);
            } else {
                ans[k - 1] = M;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
