class Solution {
public:
    int helper(vector<vector<int>>& dp, int m, int n) {
        // Base cases
        if (m == 1 && n == 1) return 1; // Reached the top-left cell
        if (m <= 0 || n <= 0) return 0; // Out of bounds
        
        // If the result for this cell has already been calculated, return it
        if (dp[m][n] != -1) return dp[m][n];
        
        // Calculate the number of unique paths using recursion
        int paths = helper(dp, m - 1, n) + helper(dp, m, n - 1);
        
        // Store the result in the memoization table
        dp[m][n] = paths;
        
        return paths;
    }

    int uniquePaths(int m, int n) {
        // Create a memoization table with dimensions (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // Start the recursion from the bottom-right corner
        return helper(dp, m, n);
    }
};
