#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    const int MAXN = 30;
    vector<ull> pow4(MAXN+1,1);
    vector<ull> pow2(MAXN+1,1);
    for(int i=1;i<=MAXN;i++){
        pow4[i] = pow4[i-1]*4ULL;
        pow2[i] = pow2[i-1]*2ULL;
    }

    while(T--){
        int n;
        cin >> n;
        int q;
        cin >> q;
        while(q--){
            string op;
            cin >> op;
            if(op == "->"){
                ull x,y;
                cin >> x >> y;
                ull d = 0;
                ull xi = x-1, yi = y-1;
                for(int k = n; k >= 1; k--){
                    ull half = pow2[k-1];
                    ull block = pow4[k-1];
                    int quad;
                    if(xi < half && yi < half){
                        quad = 0;
                    } else if(xi >= half && yi >= half){
                        quad = 1;
                        xi -= half;
                        yi -= half;
                    } else if(xi >= half && yi < half){
                        quad = 2;
                        xi -= half;
                    } else {
                        quad = 3;
                        yi -= half;
                    }
                    d += block * quad;
                }
                // base 2x2
                // mapping index to (dx,dy)
                static const int dx[4] = {0,1,1,0};
                static const int dy[4] = {0,1,0,1};
                int baseIndex;
                if(xi==0 && yi==0) baseIndex = 0;
                else if(xi==1 && yi==1) baseIndex = 1;
                else if(xi==1 && yi==0) baseIndex = 2;
                else baseIndex = 3;
                d += baseIndex;
                cout << (d+1) << "\n";
            } else {
                ull D;
                cin >> D;
                ull z = D - 1;
                ull xi = 0, yi = 0;
                for(int k = n; k >= 1; k--){
                    ull block = pow4[k-1];
                    ull half = pow2[k-1];
                    ull quad = z / block;
                    z %= block;
                    if(quad == 1){
                        xi += half;
                        yi += half;
                    } else if(quad == 2){
                        xi += half;
                    } else if(quad == 3){
                        yi += half;
                    }
                }
                static const int dx[4] = {0,1,1,0};
                static const int dy[4] = {0,1,0,1};
                xi += dx[z];
                yi += dy[z];
                cout << (xi+1) << " " << (yi+1) << "\n";
            }
        }
    }

    return 0;
}
