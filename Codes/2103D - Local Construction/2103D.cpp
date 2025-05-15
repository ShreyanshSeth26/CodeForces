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
        vector<int> a(n), d(n);
        int m = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > 0) m = max(m, a[i]);
        }
        for(int i = 0; i < n; i++){
            d[i] = (a[i] == -1 ? m+1 : a[i]);
        }

        vector<int> p(n);
        int l = 1, r = n;

        vector<int> ids_cur(n), ids_next;
        iota(ids_cur.begin(), ids_cur.end(), 0);

        for(int k = 1; k <= m; k++){
            ids_next.clear();
            int sz = ids_cur.size();
            int idx = 0;
            while(idx < sz){
                int i = ids_cur[idx];
                if(d[i] == k){
                    int start = idx;
                    while(idx < sz && d[ids_cur[idx]] == k) idx++;
                    int end = idx - 1;
                    int len = end - start + 1;

                    if(k & 1){
                        if(end == sz - 1){
                            int base = r - len + 1;
                            for(int t = 0; t < len; t++){
                                p[ ids_cur[start + t] ] = base + t;
                            }
                        } else {
                            for(int t = 0; t < len; t++){
                                p[ ids_cur[start + t] ] = r - t;
                            }
                        }
                        r -= len;
                    } else {
                        if(end == sz - 1){
                            int base = l;
                            for(int t = 0; t < len; t++){
                                p[ ids_cur[start + t] ] = base + (len - 1 - t);
                            }
                        } else {
                            int base = l;
                            for(int t = 0; t < len; t++){
                                p[ ids_cur[start + t] ] = base + t;
                            }
                        }
                        l += len;
                    }
                } else {
                    ids_next.push_back(i);
                    idx++;
                }
            }
            ids_cur.swap(ids_next);
        }

        for(int i : ids_cur){
            p[i] = l++;
        }
        for(int i = 0; i < n; i++){
            cout << p[i] << (i+1<n?' ':'\n');
        }
    }
    return 0;
}
