#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll>a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        ll x = -1;
        bool has = false, ok = true;
        for(int i = 0; i < n; i++){
            if(b[i] != -1){
                ll xi = a[i] + b[i];
                if(!has){
                    x = xi;
                    has = true;
                } else if(x != xi){
                    ok = false;
                }
            }
        }
        if(!ok){
            cout << 0 << "\n";
            continue;
        }
        if(has){
            for(int i = 0; i < n; i++){
                if(b[i] == -1){
                    ll bi = x - a[i];
                    if(bi < 0 || bi > k){
                        ok = false;
                        break;
                    }
                }
            }
            cout << (ok ? 1 : 0) << "\n";
        } else {
            ll L = 0, R = 2*k;
            for(int i = 0; i < n; i++){
                L = max(L, a[i]);
                R = min(R, a[i] + k);
            }
            ll ans = R >= L ? (R - L + 1) : 0;
            cout << ans << "\n";
        }
    }
    return 0;
}
