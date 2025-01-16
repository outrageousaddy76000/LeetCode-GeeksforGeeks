class Solution {
public:
    int helper(vector <int> &dp, vector <int> &coins, int amount){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int ans=INT_MAX/2;
        for(auto &val:coins){
            if(amount-val<0) continue;
            ans=min(ans,1+helper(dp,coins,amount-val));
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector <int> dp(amount+1,-1);
        int ans= helper(dp,coins,amount);
        return ans>=INT_MAX/2? -1:ans;
    }
};