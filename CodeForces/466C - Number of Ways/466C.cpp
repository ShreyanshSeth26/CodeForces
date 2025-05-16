#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll total = accumulate(a.begin(), a.end(), 0LL);
    if (total % 3 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    ll target = total / 3;
    ll prefixSum = 0;
    ll countFirstCuts = 0;
    ll ways = 0;
  
    for (int i = 0; i < n - 1; i++) {
        prefixSum += a[i];
        if (prefixSum == 2 * target) {
            ways += countFirstCuts;
        }
        if (prefixSum == target) {
            countFirstCuts++;
        }
    }
    cout << ways << "\n";
    return 0;
}
