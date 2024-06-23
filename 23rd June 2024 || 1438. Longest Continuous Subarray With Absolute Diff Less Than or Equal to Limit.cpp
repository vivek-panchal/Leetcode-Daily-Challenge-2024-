class Solution {
public:

    
    int longestSubarray(vector<int>& nums, int limit) {
        int j = 0,n=nums.size(),ans = 1;
        deque<int> dq1,dq2;
        dq1.push_back(0);dq2.push_back(0);
       for(int i=1;i<n;i++){
            //for mini
            while( !dq2.empty() && nums[dq2.back()] > nums[i] ) dq2.pop_back();
            dq2.push_back(i);
            int mini = nums[dq2.front()];

            //for maxi 
            while( !dq1.empty() && nums[dq1.back()] < nums[i] ) dq1.pop_back();
            dq1.push_back(i);
            int maxi = nums[dq1.front()];
            int diff = maxi-mini;
            while(diff>limit){
                if(j == dq1.front()) dq1.pop_front();
                maxi = nums[dq1.front()];
                if(j == dq2.front()) dq2.pop_front();
                mini = nums[dq2.front()];
                j++;
                diff = maxi - mini;
            }
            ans = max(ans,i-j+1);
       }
       return ans;
    }
};
