class Solution {
public:

    int solve(int i, int prev, int pos, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        if (pos == 4)
            return 1;

        if (i >= arr.size())
            return 0;

        if (dp[i][prev][pos] != -1)
            return dp[i][prev][pos];

        int ans = 0;

        // Take
        if (pos == 1 || arr[prev] < arr[i]) {
            ans += solve(i + 1, i, pos + 1, arr, dp);
        }
        // Not take
        if (pos == 1)
            ans += solve(i + 1, i + 1, pos, arr, dp);
        else
            ans += solve(i + 1, prev, pos, arr, dp);

        return dp[i][prev][pos] = ans;
    }

    int numTeams(vector<int>& arr) {
        vector<int> temp = arr;
        int n = arr.size();
        vector<vector<vector<int>>> dp(n + 4, vector<vector<int>>(n + 4, vector<int>(4, -1)));
        int ans = solve(0, 0, 1, arr, dp);
        reverse(temp.begin(), temp.end());

        dp.assign(n + 4, vector<vector<int>>(n + 4, vector<int>(4, -1))); 
        ans += solve(0, 0, 1, temp, dp);

        return ans;
    }
};
