class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    for(auto dir : dirs){
                        int newR = r + dir[0], newC = c + dir[1];
                        if(!isSafe(newR, newC, grid)){
                            perimeter++;
                        }    
                    }
                }
            }
        }
        return perimeter;
    }
private:     
    bool isSafe(int newR, int newC,vector<vector<int>>&grid){
        if(newR == grid.size() || newC == grid[0].size() || newR < 0 || newC < 0 || grid[newR][newC] == 0)return false;
        return true;
    }
};
