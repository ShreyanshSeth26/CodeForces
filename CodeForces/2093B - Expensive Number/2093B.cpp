#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int zeros = 0, best = 0;
        for(char c: s){
            if(c == '0'){
                zeros++;
            } else {
                best = max(best, zeros + 1);
            }
        }
        cout << (n - best) << "\n";
    }
    return 0;
}
