class Solution {
public:
    vector<int>temp;
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target,int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index>=candidates.size() || target<0){
            return;
        }
        
        //Take 
        temp.push_back(candidates[index]);
        solve(candidates,target-candidates[index],index+1);

        //backtrack
        temp.pop_back();

        while(index+1<candidates.size() && candidates[index]==candidates[index+1]){
            index++;
        }
        //Not take
        solve(candidates,target,index+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0);

        return ans;
    }
};
