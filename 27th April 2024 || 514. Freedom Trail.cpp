class Solution {
public:
    int fun(int n,int i,int j,string key,string ring,vector<vector<int>>&dp){
        if(j==key.size()){
            return 0;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];

        int res=INT_MAX;
        for(int k=0;k<n;k++){
            if(ring[k]==key[j]){
                int mini=min(abs(i-k),n-abs(i-k));

                res=min(res,mini+1+fun(n,k,j+1,key,ring,dp));
            }
        }
        return  dp[i][j]=res;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.length();
        vector<vector<int>>dp(n,vector<int>(key.size(),-1));
        return fun(n,0,0,key,ring,dp);
    }
};
