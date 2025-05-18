#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        const int BITS = 30; 
        vector<ll> ones(BITS, 0);
        for (int x : a) {
            for (int j = 0; j < BITS; j++) {
                if (x & (1 << j)) {
                    ones[j]++;
                }
            }
        }
        ll best = 0;
        for (int x : a) {
            ll total = 0;
            for (int j = 0; j < BITS; j++) {
                ll bitVal = 1LL << j;
                ll cnt1 = ones[j];
                ll cnt0 = n - cnt1;
                if (x & (1 << j)) {
                    total += cnt0 * bitVal;
                } else {
                    total += cnt1 * bitVal;
                }
            }
            best = max(best, total);
        }

        cout << best << "\n";
    }

    return 0;
}
