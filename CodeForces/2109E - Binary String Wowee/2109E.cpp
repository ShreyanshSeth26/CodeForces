#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;
constexpr int MAXK = 500;

static int ways[2][MAXK + 1][MAXK + 1][2];

inline void addmod(int &a, long long b) {
    a = int((a + b) % MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int s = 0; s < 2; ++s) {
        static int cur[2][MAXK + 1];
        static int nxt[2][MAXK + 1];

        for (int t = 0; t <= MAXK; ++t) {
            for (int q = 0; q < 2; ++q)
                fill(cur[q], cur[q] + MAXK + 1, 0);
            cur[0][0] = 1;

            for (int gap = 0; gap <= t; ++gap) {
                for (int q = 0; q < 2; ++q)
                    fill(nxt[q], nxt[q] + MAXK + 1, 0);

                for (int q = 0; q < 2; ++q)
                    for (int r = 0; r <= MAXK; ++r) {
                        int v = cur[q][r];
                        if (!v) continue;
                        addmod(nxt[q][r], v);

                        if (q == (s ^ (gap & 1)) && r + 1 <= MAXK)
                            addmod(nxt[q ^ 1][r + 1], v);
                    }
                for (int q = 0; q < 2; ++q)
                    copy(nxt[q], nxt[q] + MAXK + 1, cur[q]);
            }

            for (int r = 0; r <= MAXK; ++r)
                for (int q = 0; q < 2; ++q)
                    ways[s][t][r][q] = cur[q][r];
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<array<int, 2>> dp(k + 1), ndp(k + 1);
        dp[0][0] = 1;

        for (int idx = n - 1; idx >= 0; --idx) {
            int bit = s[idx] - '0';
            for (auto &a : ndp) a = {0, 0};

            for (int t = 0; t <= k; ++t)
                for (int p = 0; p < 2; ++p) {
                    int curWays = dp[t][p];
                    if (!curWays) continue;

                    const int (*tbl)[2] = ways[bit][t];
                    int rLimit = min(k - t, t + 1);
                    for (int r = 0; r <= rLimit; ++r)
                        for (int q = 0; q < 2; ++q) {
                            int w = tbl[r][q];
                            if (!w) continue;
                            int tot = t + r;
                            int pend = p ^ q;
                            addmod(ndp[tot][pend], 1LL * curWays * w);
                        }
                }
            dp.swap(ndp);
        }

        int ans = dp[k][0];
        addmod(ans, dp[k][1]);
        cout << ans << '\n';
    }
    return 0;
}
