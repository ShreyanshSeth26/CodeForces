#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        ll n, m, p, q;
        cin >> n >> m >> p >> q;

        if(p == 1){
            cout << (m == n * q ? "YES\n" : "NO\n");
            continue;
        }

        vector<ll> k(p+1);
        for(int r = 1; r <= p; r++){
            k[r] = (n - r) / p + 1;
        }

        ll g = 0;
        for(int r = 2; r <= p; r++){
            g = std::gcd(g, k[r] - k[1]);
        }
        ll D = m - k[1] * q;
        bool ok;
        if(g == 0) {
            ok = (D == 0);
        } else {
            ok = (D % g == 0);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
