#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;                                   
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int ones = 0;
        for (int &x : a) { cin >> x; ones += x; }
        bool liar = false;
        for (int i = 0; i + 1 < n; ++i)
            if (a[i] == 0 && a[i + 1] == 0) { liar = true; break; }
        if (ones > n - 1) liar = true;
        cout << (liar ? "YES\n" : "NO\n");
    }
    return 0;
}
