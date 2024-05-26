class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans = solve(n,1,2,dp);
        return dp[n][1][2];
    }
    int solve(int n,int a,int l,vector<vector<vector<int>>>&dp){
        if(a<0 || l<0)return 0;
        if(n==0)return 1;
        if(dp[n][a][l]!=-1)return dp[n][a][l];
        return dp[n][a][l] = (((solve(n-1,a,2,dp) + solve(n-1,a-1,2,dp))%1000000007) + solve(n-1,a,l-1,dp))%1000000007;
    }
};
