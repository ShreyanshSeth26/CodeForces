#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (int x : arr) {
            if (x % 2 != 0) {
                cnt++;
                if (cnt == 3) return true;
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
