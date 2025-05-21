#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> suffix_min(n+2, 0);
        for (int i = n - 1; i >= 1; --i) {
            suffix_min[i] = suffix_min[i + 1] + (s[i - 1] == '<');
        }

        vector<int> avail(n);
        iota(avail.begin(), avail.end(), 1);

        vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i) {
            int k = suffix_min[i] + 1;
            ans[i] = avail[k - 1];
            avail.erase(avail.begin() + (k - 1));
        }

        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
