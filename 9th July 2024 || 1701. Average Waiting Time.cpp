class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        int time=0;
        double ans=0;
        for(int i=0;i<nums.size();i++){
            if(i==0)
                time+=nums[i][0]+nums[i][1];
            else if(nums[i][0]>=time)
                time=nums[i][1]+nums[i][0];
            else
                time+=nums[i][1];
            ans+=time-nums[i][0];
        }
        return ans/nums.size();
    }
}; 
