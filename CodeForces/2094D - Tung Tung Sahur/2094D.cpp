#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string p, s;
        cin >> p >> s;
        vector<pair<char,int>> pb, sb;
        for(int i = 0; i < (int)p.size(); ){
            char c = p[i];
            int j = i;
            while(j < (int)p.size() && p[j] == c) j++;
            pb.emplace_back(c, j - i);
            i = j;
        }
        for(int i = 0; i < (int)s.size(); ){
            char c = s[i];
            int j = i;
            while(j < (int)s.size() && s[j] == c) j++;
            sb.emplace_back(c, j - i);
            i = j;
        }
        if(pb.size() != sb.size()){
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for(size_t i = 0; i < pb.size(); i++){
            char c1 = pb[i].first;
            char c2 = sb[i].first;
            int k = pb[i].second;
            int R = sb[i].second;
            if(c1 != c2 || R < k || R > 2*k){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
