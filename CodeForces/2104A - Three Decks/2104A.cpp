#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll num = 2*c - a - b;
        if (num % 3 != 0) {
            cout << "NO\n";
            continue;
        }
        ll k = num / 3;
        if (k < 1 || k > c) {
            cout << "NO\n";
            continue;
        }
        ll x = c - k - a;
        if (x < 0 || x > k) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
