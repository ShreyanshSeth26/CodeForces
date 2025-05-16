#include <vector>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long z1 = 0, z2 = 0;
        
        for (int x : nums1) {
            if (x == 0) ++z1;
            else sum1 += x;
        }
        for (int x : nums2) {
            if (x == 0) ++z2;
            else sum2 += x;
        }
        
        if (z1 == 0 && z2 == 0) {
            return (sum1 == sum2 ? sum1 : -1);
        }
        
        if (z1 == 0) {
            long long needed = sum2 + z2;
            return (sum1 >= needed ? sum1 : -1);
        }
        
        if (z2 == 0) {
            long long needed = sum1 + z1;
            return (sum2 >= needed ? sum2 : -1);
        }
        
        long long candidate1 = sum1 + z1;
        long long candidate2 = sum2 + z2;
        return max(candidate1, candidate2);
    }
};
