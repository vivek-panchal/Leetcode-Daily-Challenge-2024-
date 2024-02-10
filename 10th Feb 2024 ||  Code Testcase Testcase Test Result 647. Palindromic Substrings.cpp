class Solution {
public:
    int solve(int i,int j, string s, vector<vector<int>>&dp){
        if(i>j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            return dp[i][j]=solve(i+1,j-1,s,dp);
        }
        return dp[i][j]=0;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                cnt+=solve(i,j,s,dp);
            }
        }

        return cnt;
    }
};
