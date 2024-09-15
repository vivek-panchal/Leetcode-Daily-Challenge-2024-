class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> stateIndex;
        stateIndex[0] = -1;
        int state = 0;
        int maxLength = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == 'a') state ^= 1 << 0;
            else if (c == 'e') state ^= 1 << 1;
            else if (c == 'i') state ^= 1 << 2;
            else if (c == 'o') state ^= 1 << 3;
            else if (c == 'u') state ^= 1 << 4;

            if (stateIndex.find(state) != stateIndex.end()) {
                maxLength = max(maxLength, i - stateIndex[state]);
            } else {
                stateIndex[state] = i;
            }
        }

        return maxLength;
    }
};
