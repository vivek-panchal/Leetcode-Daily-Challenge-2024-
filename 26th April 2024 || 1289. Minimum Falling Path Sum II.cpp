class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int n=g.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                  int temp=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k==j){
                        continue;
                    }
                    temp=min(temp,g[i-1][k]);
                }
                if(temp!=INT_MAX);
                g[i][j]+=temp;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,g[n-1][i]);
        }
        return ans;
    }
};
