class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        
        // Initialize a 2D DP array to store the minimum number of operations needed
        // to print substrings of s[i..j].
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        // For single-character substrings, the number of operations needed is 1.
        for(int i=0; i<n; i++)
            dp[i][i] = 1;
        
        // Loop for different substring lengths (l) starting from 2 and going up to n.
        for (int l = 2; l<n+1; l++){
            // Loop through all possible starting indices of the substrings.
            for(int i=0; i<n-l+1; i++){
                // Calculate the ending index of the current substring.
                int j = i+l-1;
                
                // If the first and last characters of the substring are the same,
                // we can use the same operation used for s[i+1..j] and increment the count by 1.
                dp[i][j] = dp[i+1][j] + 1;
                
                // Loop through all possible partition points (k) within the current substring.
                for(int k=i+1; k<j+1; k++){
                    // If the character at index i is equal to the character at index k,
                    // it means we can save some operations by printing the characters s[i..k-1]
                    // together and then separately printing s[k..j].
                    if(s[i] == s[k])
                        dp[i][j] = min(dp[i][j], dp[i][k-1] + ((j>k) ? dp[k+1][j] : 0));
                }
            }
        }
        
        // The minimum number of operations needed to print the entire string s[0..n-1]
        // is stored in dp[0][n-1].
        return dp[0][n-1];
    }
};
