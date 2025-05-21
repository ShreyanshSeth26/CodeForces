#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        deque<long long> dq;
        bool rev = false;
        long long S = 0;
        long long rizz = 0;

        for (int i = 0; i < q; i++) {
            int s;
            cin >> s;

            if (s == 1) {
                int n = dq.size();
                long long val = rev ? dq.front() : dq.back();
                rizz += S - val * n;
                if (!rev) {
                    dq.pop_back();
                    dq.push_front(val);
                } else {
                    dq.pop_front();
                    dq.push_back(val);
                }
                cout << rizz << "\n";

            } else if (s == 2) {
                int n = dq.size();
                rev = !rev;
                rizz = S * (n + 1LL) - rizz;
                cout << rizz << "\n";

            } else {
                long long k;
                cin >> k;
                int n = dq.size();
                rizz += k * (n + 1LL);
                S += k;
                if (!rev) {
                    dq.push_back(k);
                } else {
                    dq.push_front(k);
                }
                cout << rizz << "\n";
            }
        }
    }

    return 0;
}
