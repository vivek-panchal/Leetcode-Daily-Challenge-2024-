class Solution {
public:
    string makeGood(string s) {
        int index = 0;
        while(index + 1 < s.length()) {
            char c1 = s[index];
            char c2 = s[index + 1];
            if(c1 + 32 == c2 || c2 + 32 == c1) {
                s.erase(s.begin() + index);
                s.erase(s.begin() + index);
                index = 0;
                continue;
            }
            index++;
        }
        return s;
    }
};
