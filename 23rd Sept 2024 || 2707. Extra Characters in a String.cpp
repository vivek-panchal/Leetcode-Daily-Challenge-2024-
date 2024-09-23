class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(s.length() + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                string substring = s.substr(j, i - j);
                if (dict.find(substring) != dict.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
                else {
                    dp[i] = min(dp[i], dp[j] + (i - j));
                }
            }
        }
        return dp[s.length()];
    }
};
