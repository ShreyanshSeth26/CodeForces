#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> G(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> G[i][j];

        int m = 2 * n;
        vector<int> p(m+1);
        vector<bool> used(m+1,false);

        for(int j = 0; j < n; j++){
            p[2 + j] = G[0][j];
            used[p[2 + j]] = true;
        }
        for(int j = 0; j < n; j++){
            p[n + 1 + j] = G[n-1][j];
            used[p[n + 1 + j]] = true;
        }

        for(int v = 1; v <= m; v++){
            if(!used[v]){
                p[1] = v;
                break;
            }
        }

        for(int i = 1; i <= m; i++){
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
