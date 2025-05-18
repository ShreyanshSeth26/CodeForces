class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";

        vector<int> cnt(n + 1, 1);
        for (int len = 1; len <= n; len++) {
            if (len == 1) cnt[len] = 3;
            else cnt[len] = 3 * (1 << (len - 1));
        }

        vector<int> suffixCount(n + 1, 1);
        for (int l = 1; l <= n; l++) {
            suffixCount[l] = 1 << l;
        }

        string result;
        result.reserve(n);
        char prev = 0;

        for (int pos = 0; pos < n; pos++) {
            for (char c : {'a','b','c'}) {
                if (c == prev) continue;
                int cntHere = suffixCount[n - pos - 1];
                if (k <= cntHere) {
                    result.push_back(c);
                    prev = c;
                    break;
                } else {
                    k -= cntHere;
                }
            }
        }
        return result;
    }
};
