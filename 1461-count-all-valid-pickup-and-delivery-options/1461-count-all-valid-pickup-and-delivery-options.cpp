class Solution {
public:
    const int mod = 1e9+7;
    int countOrders(int n) {
        vector <long long int> dp(n+1,-1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            long long int a = 2*i-1;
            a%=mod;
            dp[i]=((dp[i-1]*a)%mod)*i;
            dp[i]%=mod;
        }
        return dp[n]%mod;
    }
};