class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> firstIndex(26, -1);
        int maxLength = -1;

        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if (firstIndex[c] == -1) {
                firstIndex[c] = i;
            } else {
                maxLength = max(maxLength, i - firstIndex[c] - 1);
            }
        }

        return maxLength;
    }
};
