class Solution {
private:
    int n;
    vector <vector<int>> dp;

    int solve(int in, int valLast, string &s, int k) {
        if(in == n) return 0;
        int &res = dp[in][valLast];
        if(res != -1) return res;

        int val = (s[in] - 'a') + 1;
        int ln1, ln2 = 0;

        ln1 = solve(in+1, valLast, s, k);  
        if(valLast == 0 or abs(valLast - val) <= k) ln2 = 1 + solve(in+1, val, s, k);

        return res = max(ln1, ln2);
    }
public:
    int longestIdealString(string s, int k) {
        n = s.size();
        dp.resize(n, vector<int>(27, -1));

        return solve(0, 0, s, k);
    }
};
