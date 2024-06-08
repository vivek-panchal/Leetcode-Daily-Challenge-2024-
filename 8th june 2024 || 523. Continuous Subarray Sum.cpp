class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(m.find(sum % k) != m.end()) {
                if(i - m[sum % k] > 1) return true;
            }
            else m[sum % k] = i;
        }
        return false;
    }
};
