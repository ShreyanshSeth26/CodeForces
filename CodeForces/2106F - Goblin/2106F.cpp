#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    vector<long long> w;
    DSU(int n): p(n), w(n) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (w[ra] < w[rb]) swap(ra, rb);
        p[rb] = ra;
        w[ra] += w[rb];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        vector<bool> zeroBit(n+2, false);
        for (int i = 1; i <= n; i++) {
            zeroBit[i] = (s[i-1] == '0');
        }

        vector<int> up_id(n+2, -1), down_id(n+2, -1), diag_id(n+2, -1);
        int node_cnt = 0;
        DSU dsu(3*n + 5);

        for (int j = 1; j <= n; j++) {
            if (zeroBit[j]) {
                if (j > 1) {
                    up_id[j] = node_cnt;
                    dsu.w[node_cnt] = j - 1;
                    node_cnt++;
                }
                if (j < n) {
                    down_id[j] = node_cnt;
                    dsu.w[node_cnt] = (long long)(n - j);
                    node_cnt++;
                }
            } else {
                diag_id[j] = node_cnt;
                dsu.w[node_cnt] = 1;
                node_cnt++;
            }
        }
        for (int j = 1; j < n; j++) {
            if (zeroBit[j] && zeroBit[j+1]) {
                if (up_id[j] != -1 && up_id[j+1] != -1) {
                    dsu.unite(up_id[j], up_id[j+1]);
                }
                if (down_id[j] != -1 && down_id[j+1] != -1) {
                    dsu.unite(down_id[j], down_id[j+1]);
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (diag_id[j] != -1) {
                int dj = diag_id[j];
                if (j > 1 && zeroBit[j-1]) {
                    dsu.unite(dj, down_id[j-1]);
                }
                if (j < n && zeroBit[j+1]) {
                    dsu.unite(dj, up_id[j+1]);
                }
            }
        }
        long long answer = 0;
        for (int i = 0; i < node_cnt; i++) {
            if (dsu.find(i) == i) {
                answer = max(answer, dsu.w[i]);
            }
        }
        cout << answer << "\n";
    }

    return 0;
}
