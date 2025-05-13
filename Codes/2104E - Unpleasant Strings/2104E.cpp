#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> nextpos((n + 2) * k, -1);
    auto np = [&](int i, int c) -> int& {
        return nextpos[i * k + c];
    };

    for (int c = 0; c < k; c++) {
        np(n + 1, c) = -1;
    }
    for (int i = n; i >= 1; --i) {
        int ci = s[i - 1] - 'a';
        for (int c = 0; c < k; ++c) {
            if (c == ci) {
                np(i, c) = i;
            } else {
                np(i, c) = np(i + 1, c);
            }
        }
    }
    vector<int> f(n + 2, 0);
    f[n + 1] = 1;
    const int INF = 1e9;
    for (int i = n; i >= 1; --i) {
        bool any_missing = false;
        for (int c = 0; c < k; ++c) {
            if (np(i, c) == -1) {
                f[i] = 1;
                any_missing = true;
                break;
            }
        }
        if (any_missing) continue;
        int mn = INF;
        for (int c = 0; c < k; ++c) {
            int p = np(i, c);
            mn = min(mn, f[p + 1]);
        }
        f[i] = 1 + mn;
    }

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int pos = 1;
        bool is_subseq = true;
        for (char ch : t) {
            int c = ch - 'a';
            int p = (pos <= n + 1 ? np(pos, c) : -1);
            if (p == -1) {
                cout << 0 << '\n';
                is_subseq = false;
                break;
            }
            pos = p + 1;
        }
        if (!is_subseq) continue;
        cout << f[pos] << '\n';
    }

    return 0;
}
