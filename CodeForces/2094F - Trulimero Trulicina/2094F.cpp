#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> LAST(m, -1);

        for (int i = 0; i < n; i++) {
            bool shift = false;
            vector<int> CUR(m);
            for (int j = 0; j < m; j++) {
                int elm = static_cast<int>((1LL * i * m + j) % k) + 1;
                if (elm == LAST[j]) {
                    shift = true;
                }
                CUR[j] = elm;
            }
            if (shift) {
                vector<int> tmp(m);
                for (int j = 0; j < m; j++) {
                    tmp[j] = CUR[(j + 1) % m];
                }
                CUR.swap(tmp);
            }
            for (int j = 0; j < m; j++) {
                cout << CUR[j] << (j + 1 < m ? ' ' : '\n');
            }
            LAST = CUR;
        }
    }

    return 0;
}
