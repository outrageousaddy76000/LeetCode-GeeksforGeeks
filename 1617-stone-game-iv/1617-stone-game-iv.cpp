class Solution {
private:
    int dp[100001][2];
    bool solve(int n, int turn){
        if(n==0){
            if(turn) return true;
            return false;
        }
        if(dp[n][turn]!=-1) return dp[n][turn];
        bool ans;
        if(turn==0){
            //alice's turn
            //choose such that we get true
            ans=false;
            for(int i=1;i*i<=n;i++){
                //choose i*i stones out of n
                ans|=solve(n-i*i,1);
            }
        }
        else{
            //bob's turn
            //choose such that we get false
            ans=true;
            for(int i=1;i*i<=n;i++){
                ans&=solve(n-i*i,0);
            }
        }
        return dp[n][turn]=ans;
    }
public:
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0);
    }
};