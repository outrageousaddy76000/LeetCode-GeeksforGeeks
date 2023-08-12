class Solution {
public:
    int ans;
    int helper(int n,int m,vector <vector<int>> &v,vector <vector <int>>&dp){
        if(dp[n][m]!=-1) return dp[n][m];
        if(v[n][m]==1){
            return dp[n][m]=0;
        }
        if(n==0 && m==0){
            return dp[n][m]=1;
        }
        if(n==0){
            return dp[n][m]=helper(n,m-1,v,dp);
        }
        if(m==0) return dp[n][m]=helper(n-1,m,v,dp);
        return dp[n][m]=helper(n-1,m,v,dp) + helper(n,m-1,v,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        ans=0;
        //no of ways to reach n-1,m +n,m-1==no of ways to reach n,m
        int n = obs.size();
        int m = obs[0].size();
        if(obs[n-1][m-1]==1) return 0;
        vector <vector<int>> dp(n+1,vector <int> (m+1,-1));
        if(n==1 && m==1) return 1-obs[0][0];
        if(n-2<0) return helper(n-1,m-2,obs,dp);
        if(m-2<0) return helper(n-2,m-1,obs,dp);
        return helper(n-2,m-1,obs,dp) + helper(n-1,m-2,obs,dp);
    }
};