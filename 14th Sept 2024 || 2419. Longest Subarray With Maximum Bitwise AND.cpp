class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int count=0;
        int maxi=0;
        int maxx=*max_element(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(maxx==nums[i]){
                count++;
                maxi=max(maxi,count);
            }
            else count=0;
        }
        
        return maxi;
    }
};
