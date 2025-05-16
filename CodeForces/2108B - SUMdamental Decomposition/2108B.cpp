#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (n == 1) {
            cout << (x == 0 ? -1 : x) << "\n";
            continue;
        }

        if (x == 0) {
            if (n == 2) {
                cout << 2 << "\n";
            }
            else if (n % 2 == 0) {
                cout << n << "\n";
            }
            else {
                cout << n + 3 << "\n";
            }
            continue;
        }

        if (x == 1) {
            if (n == 2) {
                cout << 5 << "\n";
            }
            else if (n % 2 == 1) {
                cout << n << "\n";
            }
            else {
                cout << n + 3 << "\n";
            }
            continue;
        }

        int c = __builtin_popcountll(x);
        if (n <= c) {
            cout << x << "\n";
        } else {
            long long extra = n - c;
            if (extra % 2 == 0) {
                cout << x + extra << "\n";
            } else {
                cout << x + extra + 1 << "\n";
            }
        }
    }
    return 0;
}
