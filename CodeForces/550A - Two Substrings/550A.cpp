#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    size_t posAB = s.find("AB");
    if (posAB != string::npos) {
        size_t posBA = s.find("BA", posAB + 2);
        if (posBA != string::npos) {
            cout << "YES\n";
            return 0;
        }
    }

    size_t posBA = s.find("BA");
    if (posBA != string::npos) {
        size_t posAB2 = s.find("AB", posBA + 2);
        if (posAB2 != string::npos) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
