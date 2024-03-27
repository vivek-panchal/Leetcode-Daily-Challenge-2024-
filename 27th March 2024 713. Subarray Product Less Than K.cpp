class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int ans = 0, prod = 1;
        if(k <= 1) return 0;
        while(high < n){
            prod *= nums[high];
            while(prod >= k){
                prod /= nums[low];
                low++;
            }
            ans += (high - low) + 1;
            high++;
        }
        return ans;
    }
};
