class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        vector<long long>dp(points[0].begin(),points[0].end());

        for(int i=1;i<n;i++){
            long long maxi=0;
            vector<long long> temp(m);
            for(int j=0;j<m;j++){
                maxi=max(maxi,dp[j]);
                temp[j]=max(maxi+points[i][j],temp[j]);
                maxi--;
            }
            maxi=0;
            for(int j=m-1;j>=0;j--){
                maxi=max(maxi,dp[j]);
                temp[j]=max(maxi+points[i][j],temp[j]);
                maxi--;
            }
            dp=temp;
        }
        long long ans=INT_MIN;
        for(int i=0;i<dp.size();i++){
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};
