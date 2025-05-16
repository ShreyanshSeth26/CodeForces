#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<ll>> H(n, vector<ll>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> H[i][j];
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int j = 0; j < n; j++) cin >> B[j];

        vector<array<bool,3>> banned_h(n-1, {false, false, false});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + 1 < n; j++) {
                ll diff = H[i][j] - H[i][j+1];
                if (diff >= -1 && diff <= 1) {
                    banned_h[j][(int)(diff + 1)] = true;
                }
            }
        }

      vector<int> allow_y(n-1, 0);
        bool ok = true;
        for (int j = 0; j + 1 < n; j++) {
            int mask = 0;
            for (int d = -1; d <= 1; d++) {
                if (!banned_h[j][d+1]) {
                    mask |= 1 << (d + 1);
                }
            }
            if (mask == 0) {
                ok = false;
                break;
            }
            allow_y[j] = mask;
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }

        vector<array<bool,3>> banned_v(n-1, {false, false, false});
        for (int j = 0; j < n; j++) {
            for (int i = 0; i + 1 < n; i++) {
                ll diff = H[i][j] - H[i+1][j];
                if (diff >= -1 && diff <= 1) {
                    banned_v[i][(int)(diff + 1)] = true;
                }
            }
        }

      vector<int> allow_x(n-1, 0);
        for (int i = 0; i + 1 < n; i++) {
            int mask = 0;
            for (int d = -1; d <= 1; d++) {
                if (!banned_v[i][d+1]) {
                    mask |= 1 << (d + 1);
                }
            }
            if (mask == 0) {
                ok = false;
                break;
            }
            allow_x[i] = mask;
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }

        array<ll,2> dp_prev = {0, A[0]};
        array<ll,2> dp_curr;
        for (int i = 0; i + 1 < n; i++) {
            dp_curr = {INF, INF};
            for (int v1 = 0; v1 <= 1; v1++) {
                if (dp_prev[v1] >= INF) continue;
                for (int v2 = 0; v2 <= 1; v2++) {
                    int d = v2 - v1;
                    int idx = d + 1;
                    if (allow_x[i] & (1 << idx)) {
                        ll cost = dp_prev[v1] + (v2 ? A[i+1] : 0);
                        dp_curr[v2] = min(dp_curr[v2], cost);
                    }
                }
            }
            dp_prev = dp_curr;
        }
        ll best_x = min(dp_prev[0], dp_prev[1]);
        if (best_x >= INF) {
            cout << -1 << "\n";
            continue;
        }

        dp_prev = {0, B[0]};
        for (int j = 0; j + 1 < n; j++) {
            dp_curr = {INF, INF};
            for (int v1 = 0; v1 <= 1; v1++) {
                if (dp_prev[v1] >= INF) continue;
                for (int v2 = 0; v2 <= 1; v2++) {
                    int d = v2 - v1;
                    int idx = d + 1;
                    if (allow_y[j] & (1 << idx)) {
                        ll cost = dp_prev[v1] + (v2 ? B[j+1] : 0);
                        dp_curr[v2] = min(dp_curr[v2], cost);
                    }
                }
            }
            dp_prev = dp_curr;
        }
        ll best_y = min(dp_prev[0], dp_prev[1]);
        if (best_y >= INF) {
            cout << -1 << "\n";
            continue;
        }

        cout << (best_x + best_y) << "\n";
    }
    return 0;
}
