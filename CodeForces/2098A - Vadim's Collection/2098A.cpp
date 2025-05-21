#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        vector<int> digits;
        digits.reserve(10);
        for (char c : s) {
            digits.push_back(c - '0');
        }
        sort(digits.begin(), digits.end());

        string ans;
        ans.reserve(10);
        for (int i = 0; i < 10; ++i) {
            int need = 9 - i;
            auto it = lower_bound(digits.begin(), digits.end(), need);
            ans.push_back(char('0' + *it));
            digits.erase(it);
        }

        cout << ans << "\n";
    }

    return 0;
}
