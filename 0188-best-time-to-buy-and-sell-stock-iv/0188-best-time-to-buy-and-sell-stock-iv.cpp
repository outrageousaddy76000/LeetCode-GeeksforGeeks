class Solution {
private:
    int dp[1001][2][101];
    int solve(vector <int> &prices, int index,bool buy, int k){
        if(index==prices.size() || k==0) return 0;
        if(dp[index][buy][k]!=-1) return dp[index][buy][k];
        int profit=0;
        if(buy){
            //can buy
            //will buy
            profit =-1*prices[index]+solve(prices,index+1,false,k);
            //wont buy
            profit = max(profit,solve(prices,index+1,true,k));
        }
        else{
            //can sell
            //will sell
            profit =prices[index]+solve(prices,index+1,true,k-1);
            //wont buy
            profit =max(profit,solve(prices,index+1,false,k));
        }
        return dp[index][buy][k] = profit;    
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,true,k);
    }
};