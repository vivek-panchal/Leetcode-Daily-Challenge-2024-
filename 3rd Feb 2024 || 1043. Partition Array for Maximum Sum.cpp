class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size() + 1 , 0);
        for(int i=1; i<=arr.size(); i++){
            int maxi = 0;
            int maxSum = 0;
            for(int j=1; j<=k && i-j >= 0; ++j){
                maxi = max(maxi , arr[i-j]);
                maxSum = max(maxSum , dp[i-j] + maxi * j);
            }
            dp[i] = maxSum;
        }
        return dp[arr.size()];
    }
};
