class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0]; 
        int maxi = arrays[0].back();
        int ans = 0;
        
        for (int i = 1; i < arrays.size(); i++) {
            int mini1 = arrays[i][0];
            int maxi1 = arrays[i].back();
            ans = max(ans, abs(maxi1 - mini));
            ans = max(ans, abs(maxi - mini1));
            mini = min(mini, mini1);
            maxi = max(maxi, maxi1);
        }
        
        return ans;
    }
};
