#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int ceil_log2(int64 x) {
    if (x <= 1) return 0;
    x--;
    int cnt = 0;
    while (x) { ++cnt; x >>= 1; }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin >> T;
    while (T--) {
        int64 n, m, a, b;
        cin >> n >> m >> a >> b;
        int64 firstRows = min<int64>(a, n - a + 1);
        int64 firstCols = min<int64>(b, m - b + 1);
        int64 ansHorizontal = 1
                            + ceil_log2(firstRows)
                            + ceil_log2(m);
        int64 ansVertical   = 1
                            + ceil_log2(n)
                            + ceil_log2(firstCols);

        cout << min(ansHorizontal, ansVertical) << '\n';
    }
    return 0;
}
