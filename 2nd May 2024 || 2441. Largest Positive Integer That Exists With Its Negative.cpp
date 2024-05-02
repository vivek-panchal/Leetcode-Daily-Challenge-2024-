class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = nums.size() - 1;
        for (int i=0; i<nums.size();i++){
            if(i == j){
                return -1;
            }
            else if(-nums[i] == nums[j]){
                return nums[j];
            }else if(-nums[i]< nums[j]){
                j--;
                i--;                
            } 
        }
        return -1;
    }
};
