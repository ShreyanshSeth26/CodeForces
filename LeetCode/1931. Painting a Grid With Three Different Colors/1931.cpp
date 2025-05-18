class Solution {
public:
    static constexpr int MOD = 1e9+7;
    int colorTheGrid(int m, int n) {
        int maxState = 1;
        for(int i = 0; i < m; i++) maxState *= 3;
        vector<int> states;
        states.reserve(maxState);
        for(int mask = 0; mask < maxState; mask++){
            int x = mask;
            bool ok = true;
            int prev = x % 3;
            x /= 3;
            for(int i = 1; i < m; i++, x /= 3){
                int c = x % 3;
                if(c == prev){ ok = false; break; }
                prev = c;
            }
            if(ok) states.push_back(mask);
        }
        int S = states.size();
        
        vector<vector<int>> compat(S);
        for(int i = 0; i < S; i++){
            for(int j = 0; j < S; j++){
                int a = states[i], b = states[j];
                bool ok = true;
                for(int k = 0; k < m; k++){
                    if((a % 3) == (b % 3)){ ok = false; break; }
                    a /= 3; b /= 3;
                }
                if(ok) compat[i].push_back(j);
            }
        }
        
        vector<int> dp(S, 1), ndp(S);
        for(int col = 1; col < n; col++){
            fill(ndp.begin(), ndp.end(), 0);
            for(int i = 0; i < S; i++){
                if(dp[i] == 0) continue;
                int ways = dp[i];
                for(int j: compat[i]){
                    ndp[j] = (ndp[j] + ways) % MOD;
                }
            }
            dp.swap(ndp);
        }
        
        long long ans = 0;
        for(int v: dp) ans = (ans + v) % MOD;
        return ans;
    }
};
