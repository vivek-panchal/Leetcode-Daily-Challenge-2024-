class Solution {
public:
    int findlocalmax(vector<vector<int>>& grid,int row,int col){
        int maxi=INT_MIN;
        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2;j++){
                maxi=max(maxi,grid[i][j]);
            }
        }
      return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> maxlocal(n-2,vector<int>(n-2));

        for(int row=0;row<n-2;row++){
           for(int col=0;col<n-2;col++){
              maxlocal[row][col]=findlocalmax(grid,row,col);
           }
        }
        return maxlocal;
    }
};
