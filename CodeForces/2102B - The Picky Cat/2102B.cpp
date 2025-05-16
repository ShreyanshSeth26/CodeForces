#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int v = abs(a[0]);
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(abs(a[i]) < v) 
                cnt++;
        }
        if(cnt <= n/2) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}
