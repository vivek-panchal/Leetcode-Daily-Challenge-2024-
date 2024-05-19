class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

        vector<int> delta(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            delta[i] = (nums[i] ^ k) - nums[i];
        }
        
        sort(delta.begin(), delta.end(), greater<int>());
        
        long long res = accumulate(nums.begin(), nums.end(), 0LL);
        
        for (size_t i = 0; i < nums.size(); i += 2) {
            if (i == nums.size() - 1) {
                break;
            }
            int path_delta = delta[i] + delta[i + 1];
            if (path_delta <= 0) {
                break;
            }
            res += path_delta;
        }
        return res;
    }
};
