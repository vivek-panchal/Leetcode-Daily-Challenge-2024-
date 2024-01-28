class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 1;j < m;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        unordered_map<int,int>mpp;
        int ans = 0;
        for(int start = 0;start < m;start++){
            
            for(int end = start;end < m;end++){
                
                mpp.clear();
                mpp[0]++;
                int sum = 0;
                for(int i = 0;i < n;i++){
                    int curr = matrix[i][end];
                    if(start > 0){
                        curr -= matrix[i][start-1];
                    }
                    sum += curr;
                    ans += mpp[sum-target];
                    mpp[sum]++;
                }
            }
        }
        return ans;
    }
};
