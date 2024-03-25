class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]++;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
