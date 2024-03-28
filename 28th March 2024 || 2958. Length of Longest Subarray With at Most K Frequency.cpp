class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        int start=0;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>k){
                while(start<i && nums[start]!=nums[i]){
                    mp[nums[start]]--;
                    start++;
                }
                mp[nums[start]]--;
                start++;
            }
            maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};
