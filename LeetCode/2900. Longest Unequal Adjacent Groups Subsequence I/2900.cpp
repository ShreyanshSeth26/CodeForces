#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        auto build = [&](int startBit) {
            vector<string> res;
            int curr = startBit;
            for (int i = 0; i < n; ++i) {
                if (groups[i] == curr) {
                    res.push_back(words[i]);
                    curr ^= 1;
                }
            }
            return res;
        };
        
        auto seq0 = build(0);
        auto seq1 = build(1);
        return (seq0.size() > seq1.size() ? seq0 : seq1);
    }
};
