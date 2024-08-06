class Solution {
public:
    int solve(int x,int y, vector <vector <int>> &grid,vector <vector <int>> &dp){
        if(dp[x][y]!=-1) return dp[x][y];
        int right = INT_MAX;
        int down = INT_MAX;
        if(x+1<grid.size()){
            down = solve(x+1,y,grid,dp);
        }
        if(y+1<grid[0].size()){
            right = solve(x,y+1,grid,dp);
        }
        if(down==INT_MAX && right==INT_MAX) return dp[x][y]=grid[x][y];
        return dp[x][y]=grid[x][y] + min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector <vector <int>> dp(grid.size(),vector <int> (grid[0].size(),-1));
        return solve(0, 0, grid,dp);
    }
};