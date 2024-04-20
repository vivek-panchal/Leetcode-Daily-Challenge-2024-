const int Maxn = 4;
class Solution {
public:
    int dx[Maxn] = { -1, 0, 1,  0 };
    int dy[Maxn] = {  0, 1, 0, -1 };

    void dfs(vector<vector<int>> &land,vector<vector<bool>> &vis,vector<int> &res,int r,int c,int n,int m) {
        if ( r < 0 | r == n | c < 0 | c == m ) return;
        if ( vis[r][c] ) return;
        vis[r][c] = true;
        if ( !land[r][c] ) return;
        res[2] = std::max({res[2],r});
        res[3] = std::max({res[3],c});
        for ( int i = 0 ; i < Maxn ; i++ ) {
            dfs(land,vis,res,r+dx[i],c+dy[i],n,m);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( !vis[i][j] && land[i][j] ) {
                    vector<int> res(4);
                    res[0] = i; res[1] = j;
                    res[2] = i; res[3] = j;
                    dfs(land,vis,res,i,j,n,m);
                    ans.emplace_back(res);
                }
            }
        }
        return ans;
    }
};
