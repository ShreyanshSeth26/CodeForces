#include <bits/stdc++.h>
using namespace std;

static const int S = 100005;
using ll = long long;

ll a[S], d[S], n;

bool check(ll ans) {
    memset(d, 0, sizeof(ll) * n);
    ll acc = 0;
    
    for (ll i = 0; i < n; ++i) {
        acc -= d[i];
        
        ll need = max(0LL, i - (n - ans));
        if (acc < need) return false;
        
        ll end = i + a[i] + (acc++) - need + 1;
        if (end < n) ++d[end];
    }
    
    return true;
}

void solve() {
    scanf("%lld", &n);
    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    
    ll le = 1, ri = n + 1, mid;
    while (ri - le > 1) {
        mid = (le + ri) / 2;
        if (check(mid)) le = mid;
        else ri = mid;
    }
    
    printf("%lld\n", le);
}

int main() {
    ll tc;
    scanf("%lld", &tc);
    while (tc--) {
        solve();
    }
    return 0;
}
