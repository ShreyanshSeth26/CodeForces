class Solution {
public:
    int hammingDistance(const string& a, const string& b) {
        int dist = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++dist;
        }
        return dist;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && 
                    words[i].length() == words[j].length() &&
                    hammingDistance(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }

        int maxLen = 0, endIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIdx = i;
            }
        }

        vector<string> result;
        while (endIdx != -1) {
            result.push_back(words[endIdx]);
            endIdx = prev[endIdx];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
