class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& nums,int n){
        if(n==nums.size()){
            ans.push_back(temp);
            return;
        }

        //not take 
        solve(nums,n+1);
        //take
        temp.push_back(nums[n]);
        solve(nums,n+1);
        //backtracking
        temp.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};
