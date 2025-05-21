#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        auto can = [&](int x) {
            vector<char> seen(x);
            int distinct = 0, segments = 0;
            for (int v : a) {
                if (v < x && !seen[v]) {
                    seen[v] = 1;
                    distinct++;
                }
                if (distinct == x) {
                    segments++;
                    if (segments == k) return true;
                    distinct = 0;
                    fill(seen.begin(), seen.end(), 0);
                }
            }
            return segments >= k;
        };

        int low = 0, high = n + 1;
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            if (can(mid)) low = mid;
            else high = mid - 1;
        }
        cout << low << "\n";
    }

    return 0;
}
