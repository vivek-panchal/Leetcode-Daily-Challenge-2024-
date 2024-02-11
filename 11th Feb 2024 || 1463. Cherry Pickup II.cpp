class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
            int m=grid[0].size();
            int n=grid.size();
            vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
      (m, 0));

      for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
          if (j1 == j2)
            front[j1][j2] = grid[n - 1][j1];
          else
            front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
      }

      //Outer Nested Loops for travering DP Array
      for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
          for (int j2 = 0; j2 < m; j2++) {

            int maxi = INT_MIN;

            //Inner nested loops to try out 9 options
            for (int di = -1; di <= 1; di++) {
              for (int dj = -1; dj <= 1; dj++) {

                int ans;

                if (j1 == j2)
                  ans = grid[i][j1];
                else
                  ans = grid[i][j1] + grid[i][j2];

                if ((j1 + di < 0 || j1 + di >= m) ||
                  (j2 + dj < 0 || j2 + dj >= m))

                  ans += -1e9;
                else
                  ans += front[j1 + di][j2 + dj];

                maxi = max(ans, maxi);

              }
            }
            cur[j1][j2] = maxi;
          }
        }
        front = cur;
      }

      return front[0][m - 1];
    }
};
