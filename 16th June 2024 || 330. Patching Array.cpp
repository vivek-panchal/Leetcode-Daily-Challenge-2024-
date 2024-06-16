class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long curr=0;
        long long i=0;
        long long ans=0;

        while(curr<n){
            if(i<nums.size() && curr+1>=nums[i]){
                curr+=nums[i];
                i++;
            }
            else{
                curr =2*curr+1;
                ans++;
            }
          
        }
        return ans;

    }
};
