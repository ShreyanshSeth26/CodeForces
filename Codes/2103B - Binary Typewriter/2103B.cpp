#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int t = 0;
        if (s[0] == '1') t++;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) t++;
        }

        vector<int> pos01, pos10;
        for (int b = 0; b < n; b++) {
            char c1 = (b == 0 ? '0' : s[b - 1]);
            char c2 = s[b];
            if (c1 != c2) {
                if (c1 == '0')
                    pos01.push_back(b);
                else
                    pos10.push_back(b);
            }
        }

        int max_saving = 0;

        bool sav2 = false;
        if (pos01.size() >= 2 && pos01.back() - pos01.front() >= 2) sav2 = true;
        if (pos10.size() >= 2 && pos10.back() - pos10.front() >= 2) sav2 = true;
        if (sav2) {
            max_saving = 2;
        } else {
            bool sav1 = false;
            if (!pos01.empty() && s[n - 1] == '0') sav1 = true;
            if (!pos10.empty() && s[n - 1] == '1') sav1 = true;
            if (sav1) max_saving = 1;
        }

        ll answer = (ll)n + t - max_saving;
        cout << answer << "\n";
    }

    return 0;
}
