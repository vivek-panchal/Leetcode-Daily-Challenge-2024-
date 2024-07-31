class Solution {
public:
    int solve(vector<vector<int>>& books, int ind, int rw, int height, int sw, vector<vector<int>> &dp){

        if(ind >= books.size()) return height;
        
        if(dp[ind][rw] != -1) return dp[ind][rw];

        int opt1 = INT_MAX;
        if(rw >= books[ind][0]){
            int hforopt1 = max(height, books[ind][1]);
            opt1 = solve(books, ind+1, rw-books[ind][0], hforopt1, sw, dp);
        }

        int opt2 = height + solve(books, ind + 1, sw - books[ind][0], books[ind][1], sw, dp);

        dp[ind][rw] = min(opt1, opt2);
        return min(opt1, opt2);

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth + 1, -1));
        int ans = solve(books, 0, shelfWidth, 0, shelfWidth, dp);

        return ans;
    }
};
