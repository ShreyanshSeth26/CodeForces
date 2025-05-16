#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        vector<int> c(n+1);
        for(int i = 1; i <= n; i++){
            c[i] = (a[i] <= k ? +1 : -1);
        }

        vector<int> P(n+1, 0);
        for(int i = 1; i <= n; i++){
            P[i] = P[i-1] + c[i];
        }

        vector<int> Q(n+2, 0);
        for(int i = n; i >= 1; i--){
            Q[i] = Q[i+1] + c[i];
        }

        bool ok = false;
        if(!ok){
            vector<int> sufMax(n+2, INT_MIN);
            for(int j = n-1; j >= 2; j--){
                sufMax[j] = max(P[j], sufMax[j+1]);
            }
            for(int i = 1; i <= n-2; i++){
                if (P[i] >= 0 && sufMax[i+1] >= P[i]) {
                    ok = true;
                    break;
                }
            }
        }
        if(!ok){
            vector<int> c_rev(n+1);
            for(int i = 1; i <= n; i++){
                c_rev[i] = c[n - i + 1];
            }
            vector<int> P_rev(n+1, 0);
            for(int i = 1; i <= n; i++){
                P_rev[i] = P_rev[i-1] + c_rev[i];
            }
            vector<int> sufMaxRev(n+2, INT_MIN);
            for(int j = n-1; j >= 2; j--){
                sufMaxRev[j] = max(P_rev[j], sufMaxRev[j+1]);
            }
            for(int i = 1; i <= n-2; i++){
                if (P_rev[i] >= 0 && sufMaxRev[i+1] >= P_rev[i]) {
                    ok = true;
                    break;
                }
            }
        }
        if(!ok){
            vector<bool> sufAny(n+3, false);
            for(int p = n; p >= 1; p--){
                sufAny[p] = (Q[p] >= 0) || sufAny[p+1];
            }
            for(int i = 1; i <= n-2; i++){
                if (P[i] >= 0 && sufAny[i+2]) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
