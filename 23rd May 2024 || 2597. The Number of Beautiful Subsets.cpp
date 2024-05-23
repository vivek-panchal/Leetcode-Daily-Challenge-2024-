class Solution {
public:
    int solve(int index, vector<int>& nums, unordered_map<int, int>& map, int k){
        if (index == nums.size()) {
            if (!map.empty()) return 1;
            return 0;
        }
        int include = 0;
        if (map.find(nums[index] + k) == map.end() && map.find(nums[index] - k) == map.end()) {
            map[nums[index]]++;
            include = solve(index + 1, nums, map, k);
            map[nums[index]]--;
            if (map[nums[index]] == 0) map.erase(nums[index]);
        }
        int exclude = solve(index + 1, nums, map, k);
        return include + exclude;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        return solve(0, nums, map, k);
    }
};
