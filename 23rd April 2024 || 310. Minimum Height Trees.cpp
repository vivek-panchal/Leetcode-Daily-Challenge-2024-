class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjmat(n,vector<int>(0));
        vector<int> cnt(n,0);
        for(auto e:edges){
            adjmat[e[0]].push_back(e[1]);
            adjmat[e[1]].push_back(e[0]);
            cnt[e[0]]++;
            cnt[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) if(cnt[i] == 1) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int x = q.size();
            ans.clear();
            for(int i = 0; i < x; i++){
                int z = q.front();
                q.pop();
                ans.push_back(z);
                for(auto u : adjmat[z]){
                    cnt[u]--;
                    if(cnt[u] == 1) q.push(u);
                }
            }
        }
        if(n == 1) ans.push_back(0);
        return ans;
    }
};
