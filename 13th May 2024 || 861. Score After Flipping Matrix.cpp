class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans = (1<<(n-1))*m;
        for(int col = 1 ;col < n;col++)
        {
            int countSame=0;
            for(int row=0;row<m;row++)
            {
                if(grid[row][col]==grid[row][0])
                {
                    countSame++;
                }
            }
            countSame=max(countSame,m-countSame);
            ans+=(1<<(n-col-1))*countSame;
        }
        return ans;
    }
};
