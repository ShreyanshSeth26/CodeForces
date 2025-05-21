#include <bits/stdc++.h>
using namespace std;

// Returns true if card 'a' beats card 'b' under the cyclic rule:
//   - If a == 1 and b == n, then a beats b.
//   - Else if a == n and b == 1, then a does NOT beat b.
//   - Otherwise, a beats b iff a > b.
bool beats(int a, int b, int n) {
    if (a == 1 && b == n) return true;
    if (a == n && b == 1) return false;
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> alice_cards, bob_cards;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') alice_cards.push_back(i + 1);
            else              bob_cards.push_back(i + 1);
        }

        // Check if Bob can respond to every Alice card with some b that
        // Alice does NOT beat (i.e., beats(a,b) == false).
        bool bob_wins = true;
        for (int a : alice_cards) {
            bool has_safe_response = false;
            for (int b : bob_cards) {
                if (!beats(a, b, n)) {
                    // Bob plays b and wins this trick.
                    has_safe_response = true;
                    break;
                }
            }
            if (!has_safe_response) {
                // Alice has a card 'a' that Bob cannot beat -> Alice wins.
                bob_wins = false;
                break;
            }
        }

        cout << (bob_wins ? "Bob\n" : "Alice\n");
    }

    return 0;
}
