class Solution {
public:
    void solve(int j,int i,vector<vector<int>> &ans,vector<vector<int>> &adj,vector<bool> &vis){
        vis[j]=1;
        for(auto it:adj[j]){
            if(!vis[it]){
                ans[it].push_back(i);
                solve(it,i,ans,adj,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n),adj(n);
        for(auto it:edges){ 
            adj[it[0]].push_back(it[1]); 
        } 
        for(int i=0;i<n;i++){ 
            vector<bool> vis(n,0);
            solve(i,i,ans,adj,vis);
        }
        return ans;
    }
};
