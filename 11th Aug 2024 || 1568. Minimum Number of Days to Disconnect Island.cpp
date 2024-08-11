class Solution {
public:
    void dfs(vector<vector<int>> &grid1,int i,int j){
        int m = grid1.size(), n = grid1[0].size();
        if(i<0 || i>=m || j<0|| j>=n || grid1[i][j]==0){
            return;
        }
        grid1[i][j]=0;
        dfs(grid1,i+1,j);
        dfs(grid1,i,j+1);
        dfs(grid1,i-1,j);
        dfs(grid1,i,j-1);
    }
    int countIslands(vector<vector<int>> &grid){
        int num=0;
        vector<vector<int>> grid1=grid;
        for(int i=0; i<grid1.size(); i++){
            for(int j=0; j<grid1[0].size();j++){
                if(grid1[i][j]==1){
                    num++;
                    dfs(grid1,i,j);
                }
            }
        }
        return num;
    }
    int minDays(vector<vector<int>>& grid) {
        if(countIslands(grid)!=1){
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(countIslands(grid)!=1){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};
