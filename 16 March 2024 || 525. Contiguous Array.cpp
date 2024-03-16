class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> Map;
        Map[0] = -1;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0? -1: 1;
            if(Map.find(sum) == Map.end()) Map[sum] = i;
            ans = max(ans, i - Map[sum]);
        }
        return ans;
    }
};
