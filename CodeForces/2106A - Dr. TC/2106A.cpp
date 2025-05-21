#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, count = 0;
        string s;
        cin >> n >> s;
        for (char c : s)
            if (c == '1') count++;
        cout << count * (n - 1) + (n - count) << "\n";
    }
    return 0;
}
