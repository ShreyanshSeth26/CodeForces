#include <vector>
#include <string>
#include <array>
using namespace std;

class Solution {
    static const int K = 26;
    static const int MOD = 1'000'000'007;
    using Mat = array<array<long long, K>, K>;

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        if (t == 0) return (int)s.size();
        Mat A{};
        for (int c = 0; c < K; ++c) {
            for (int k = 1; k <= nums[c]; ++k) {
                int d = (c + k) % K;
                A[c][d] = (A[c][d] + 1) % MOD;
            }
        }

        Mat M = matPow(A, t);
        vector<long long> freq(K, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        long long ans = 0;
        for (int c = 0; c < K; ++c) {
            if (freq[c] == 0) continue;
            long long lengthFromC = 0;
            for (int d = 0; d < K; ++d) {
                lengthFromC = (lengthFromC + M[c][d]) % MOD;
            }
            ans = (ans + freq[c] * lengthFromC) % MOD;
        }
        return (int)ans;
    }

private:
    Mat matMul(const Mat& X, const Mat& Y) {
        Mat Z{};
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                __int128 sum = 0;
                for (int k = 0; k < K; ++k) {
                    sum += (__int128)X[i][k] * Y[k][j];
                }
                Z[i][j] = (long long)(sum % MOD);
            }
        }
        return Z;
    }
    Mat matPow(Mat base, long long exp) {
        Mat res{};
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                res[i][j] = (i == j);
            }
        }
        while (exp > 0) {
            if (exp & 1) res = matMul(res, base);
            base = matMul(base, base);
            exp >>= 1;
        }
        return res;
    }
};
