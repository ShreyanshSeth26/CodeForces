#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long k = n / 2;
        long long ans = k * (n - k) + 1;
        cout << ans << "\n";
    }
    return 0;
}
