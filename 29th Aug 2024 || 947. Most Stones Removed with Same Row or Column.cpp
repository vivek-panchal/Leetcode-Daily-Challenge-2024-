class Solution {
    unordered_map<int,vector<int> > gr,gc;
    map<pair<int,int>,int > vis;
    int co;
public:
    void dfs(int i,int j){
        co++;
        vis[{i,j}]=1;
       // cout<<i<<" "<<j<<"\n";
        for(auto y:gc[i]){
            if(y!=j && !vis[{i,y}]){ 
                dfs(i,y);
            }
        }
        for(auto x:gr[j]){
            if(x!=i && !vis[{x,j}]){
                dfs(x,j);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        for(auto s:stones){
            gc[s[0]].push_back(s[1]);
            gr[s[1]].push_back(s[0]);
        }
        int n=stones.size();
        int ma=0;
        for(auto s:stones){
            co=0;
            dfs(s[0],s[1]);
            ma+=co-1;
            
        }
        return ma;
    }
};
