class Solution {
public:
    vector <vector<int>> dp;
    int n;
    int helper(int target,int m,vector <int> &coins){
        if(dp[target][m]!=-1){
            return dp[target][m];
        }
        if(m>=n || target<0) return dp[target][m]=0;
        if(target==0) return dp[target][m]=1;
        if(target<coins[m]){
            return dp[target][m]=0;
        }
        if(target==coins[m]){
            return dp[target][m]=1;
        }
        else{
            int a = helper(target-coins[m],m,coins);
            int b = helper(target,m+1,coins);
            return dp[target][m]=a+b;
        }
    }
    int change(int target, vector<int>& coins) {
        //unbound knapsack
        n = coins.size();
        sort(coins.begin(),coins.end());
        dp.resize(target+1,vector <int> (n+1,-1));
        return helper(target,0,coins);
    }
};