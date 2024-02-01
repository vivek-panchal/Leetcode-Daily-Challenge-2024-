class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
       
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        for(int i=0;i<n;i+= 3){
            
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            if(abs(a-b)<=k && abs(b-c)<=k && abs(c-a)<=k){
                ans.push_back({a,b,c});
            }
            else{
                return {};
            }
        }
        return ans;
    }
};
