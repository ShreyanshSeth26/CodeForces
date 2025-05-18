#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n+1), pos(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            int pk = pos[k];
            if (pk < l || pk > r) {
                cout << -1 << "\n";
                continue;
            }

            int lo = l, hi = r;
            int misL = 0, misR = 0;
            int lcnt = 0, rcnt = 0;

            while (lo <= hi) {
                int m = lo + (hi - lo) / 2;
                if (m == pk) break;

                if (m < pk) {
                    ++lcnt;
                    if (p[m] > k) ++misL;
                    lo = m + 1;
                } else {
                    ++rcnt;
                    if (p[m] < k) ++misR;
                    hi = m - 1;
                }
            }
            if (lcnt > k - 1 || rcnt > n - k) {
                cout << -1 << "\n";
            } else {
                cout << 2 * max(misL, misR) << "\n";
            }
        }
    }
    return 0;
}
