class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        if(nums.size() <= 4){
            return 0 ;
        }
        else{
            int answer1 = nums[nums.size() - 1] - nums[3];
            int answer2 = nums[nums.size() - 2] - nums[2];
            int answer3 = nums[nums.size() - 3] - nums[1];
            int answer4 = nums[nums.size() - 4] - nums[0];
            return min(min(answer1,answer2) , min(answer3 , answer4));
        }
    }
};
