class Solution {
public:
    vector<vector<int>> mat1,mat2;
    int n,m;
    vector<int> dr={-1,0,1,0},dc={0,-1,0,1};
    bool isSubIsland(int r,int c,vector<vector<bool>> &vis){
        vis[r][c]=true;
        mat2[r][c]=-1;
        bool ans = true;
        for(int k=0;k<4;k++){
            int nr = r + dr[k],nc = c + dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat2[nr][nc]==1){
                if(!mat1[nr][nc])
                    ans = false;
                ans = ans & isSubIsland(nr,nc,vis);
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        n=grid1.size(),m=grid1[0].size();
        mat1=grid1,mat2=grid2;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat2[i][j]==1 && mat1[i][j]==1)
                    ans+=isSubIsland(i,j,vis);
            }
        }
        return ans;
    }
};
