class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
       long long int peri=accumulate(nums.begin(),nums.end(),0ll);
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            if(peri-nums[i]>nums[i]){
               return peri;
            }
            else{
               peri-=nums[i];
            }
        }
        return -1;
    }
};
