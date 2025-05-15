#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        vector<pair<ll,int>> v;
        v.reserve(n);
        for (ll x : a) {
            if (v.empty() || v.back().first != x) {
                v.emplace_back(x, 1);
            } else {
                v.back().second++;
            }
        }

        bool ok = false;
        int m = v.size();
        int i = 0;
        while (i < m && !ok) {
            int j = i;
            while (j + 1 < m && v[j+1].first == v[j].first + 1) {
                j++;
            }
            int cnt2 = 0;
            for (int k = i; k <= j; k++) {
                if (v[k].second >= 4) {
                    ok = true;
                    break;
                }
                if (v[k].second >= 2) {
                    cnt2++;
                }
            }
            if (ok) break;
            if (cnt2 >= 2) {
                ok = true;
                break;
            }
            i = j + 1;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
