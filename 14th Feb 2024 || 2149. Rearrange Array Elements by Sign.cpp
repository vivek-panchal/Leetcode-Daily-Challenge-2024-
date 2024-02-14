class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int odd=1;
        int even=0;

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[even]=nums[i];
                even+=2;
            }
            if(nums[i]<0){
                ans[odd]=nums[i];
                odd+=2;
            }
        }
        return ans;
    }
};
