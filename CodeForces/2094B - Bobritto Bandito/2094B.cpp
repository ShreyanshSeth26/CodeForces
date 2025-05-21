#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int lp = max(l, -m);
        int rp = lp + m;
        cout << lp << " " << rp << "\n";
    }
    return 0;
}
