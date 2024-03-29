class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());

        int i =0 ,j=0;
        long long Result =0;
        int MaxEleCount =0;
        while(j<nums.size()){
            if(nums[j]==maxEle) MaxEleCount++;
            while(MaxEleCount>=k){
                Result+=nums.size()-j;
                if(nums[i]==maxEle){
                     MaxEleCount--;
                }
                i++;
            }
            j++;
        }
        return Result;  
    }
};
