#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    static const int MOD = 1'000'000'007;

    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        if (t == 0) {
            return n % MOD;
        }
        
        vector<int> dp(26, 1), nextDp(26);
        
        for (int step = 1; step <= t; ++step) {
            for (int c = 0; c < 25; ++c) {
                nextDp[c] = dp[c+1];
            }
            nextDp[25] = (dp[0] + dp[1]) % MOD;
            
            dp.swap(nextDp);
        }
        
        long long ans = 0;
        for (char ch : s) {
            ans = (ans + dp[ch - 'a']) % MOD;
        }
        return (int)ans;
    }
};
