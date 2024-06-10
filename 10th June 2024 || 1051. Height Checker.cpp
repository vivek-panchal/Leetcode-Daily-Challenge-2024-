class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>exp=heights;
        sort(heights.begin(),heights.end());
        int n = heights.size(),ans=0;
        for(int i=0;i<n;i++){
            if(heights[i]!=exp[i]) ans++;
        }
        return ans;
    }
};
