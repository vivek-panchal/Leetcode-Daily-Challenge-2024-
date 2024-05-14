class Solution {
    int directions[4][2] = {
        {-1,0},{0,1},{1,0},{0,-1}
    };
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxi = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    maxi = max(maxi, grid[i][j] + f(i, j, grid));
                }
            }
        }
        return maxi;
    }

    int f(int i, int j, vector<vector<int>>& grid){
        int originalGold = grid[i][j];
        grid[i][j] = 0;

        int coinsCollected = 0;
        for(auto direction : directions){
            int dI = i + direction[0];
            int dJ = j + direction[1];

            if(insideGrid(dI, dJ, grid) && grid[dI][dJ] > 0){
                coinsCollected = max(coinsCollected, grid[dI][dJ] + f(dI, dJ, grid));
            }
        }

        grid[i][j] = originalGold;
        
        return coinsCollected;
    }

    bool insideGrid(int i, int j, vector<vector<int>>& grid){
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
};
