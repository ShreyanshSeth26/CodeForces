#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXK = 100000;

int spf[MAXK+1];
vector<int> posList[MAXK+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i <= MAXK; ++i){
        if(spf[i] == 0){
            spf[i] = i;
            if ((ll)i * i <= MAXK) {
                for(int j = i * i; j <= MAXK; j += i){
                    if(spf[j] == 0) spf[j] = i;
                }
            }
        }
    }

    int t;
    cin >> t;
    vector<int> usedValues;
    usedValues.reserve(100000);
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        usedValues.clear();
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            if(a[i] <= MAXK){
                if(posList[a[i]].empty()){
                    usedValues.push_back(a[i]);
                }
                posList[a[i]].push_back(i);
            }
        }
        while(q--){
            int k0, l, r;
            cin >> k0 >> l >> r;
            int k = k0;

            vector<pair<int,int>> fac;
            int x = k0;
            while(x > 1){
                int p = spf[x], cnt = 0;
                while(x % p == 0){
                    x /= p;
                    ++cnt;
                }
                fac.emplace_back(p, cnt);
            }
            vector<int> divs = {1};
            for(auto &pr : fac){
                int p = pr.first, cnt = pr.second;
                int sz = divs.size();
                ll mul = 1;
                for(int e = 1; e <= cnt; ++e){
                    mul *= p;
                    for(int i = 0; i < sz; ++i){
                        divs.push_back(divs[i] * mul);
                    }
                }
            }
            if(!divs.empty() && divs[0] == 1){
                divs.erase(divs.begin());
            }

            ll ans = 0;
            int pos = l;
            if(divs.empty()){
                ans = (ll)k * (r - l + 1);
                cout << ans << "\n";
                continue;
            }
            while(pos <= r && k > 1){
                int next_i = r + 1;
                for(int d : divs){
                    if(d > k || k % d != 0) continue;
                    auto &vec = posList[d];
                    auto it = lower_bound(vec.begin(), vec.end(), pos);
                    if(it != vec.end() && *it <= r){
                        next_i = min(next_i, *it);
                    }
                }
                if(next_i > r) break;
                ans += (ll)k * (next_i - pos);
                int v = a[next_i];
                while(k % v == 0){
                    k /= v;
                }
                ans += k;
                pos = next_i + 1;
            }
            if(pos <= r){
                ans += (ll)k * (r - pos + 1);
            }
            cout << ans << "\n";
        }
        for(int v : usedValues){
            posList[v].clear();
        }
    }

    return 0;
}
