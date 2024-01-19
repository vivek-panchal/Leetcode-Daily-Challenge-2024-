class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int mini=INT_MAX;
        vector<int>prev(n,0);
        for(int j=0;j<n;j++){
            prev[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                int down= matrix[i][j]+ prev[j];
                int left=INT_MAX ;
                if(j+1<n)left= matrix[i][j]+prev[j+1];
                int right=INT_MAX;  ;
                if(j>0) right=matrix[i][j] + prev[j-1];

                curr[j]=min(down,min(left,right));
            }
            prev=curr;
        }
        for(int j=0;j<n;j++){
            mini=min(mini,prev[j]);
        }
        return mini;
    }
};










