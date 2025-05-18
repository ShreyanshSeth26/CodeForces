#include <bits/stdc++.h>
 
using namespace std;
 
const int LOG_X = 29;
 
struct node {
    int children[2] { -1, -1 };
    int last = -1;
};
 
int find(const vector<node>& trie, int value, int border) {
    int res = -1;
    int current = 0;
    bool ok = true;
    for (int position = LOG_X; ok && position >= 0; position--) {
        int x_bit = (value >> position) & 1;
        int k_bit = (border >> position) & 1;
        auto& children = trie[current].children;
        if (k_bit == 1) {
            if (children[x_bit ^ 1] != -1) {
                current = children[x_bit ^ 1];
            } else {
                ok = false;
            }
        } else {
            if (children[x_bit ^ 1] != -1) {
                res = max(res, trie[children[x_bit ^ 1]].last);
            }
            if (children[x_bit] != -1) {
                current = children[x_bit];
            } else {
                ok = false;
            }
        }
    }
    if (ok) {
        res = max(res, trie[current].last);
    }
    return res;
}
 
void add(vector<node>& trie, int value, int index) {
    int current = 0;
    trie[current].last = max(trie[current].last, index);
    for (int position = LOG_X; position >= 0; position--) {
        int x_bit = (value >> position) & 1;
        if (trie[current].children[x_bit] == -1) {
            trie[current].children[x_bit] = trie.size();
            trie.push_back(node());
        }
        current = trie[current].children[x_bit];
        trie[current].last = max(trie[current].last, index);
    }
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    int ans = n + 1;
    vector<node> trie(1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(trie, x, i);
        int y = find(trie, x, k);
        if (y != -1) {
            ans = min(ans, i - y + 1);
        }
    }
 
    if (ans == n + 1) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
}
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
 
    return 0;
}
