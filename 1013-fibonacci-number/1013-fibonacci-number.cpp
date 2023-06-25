class Solution {
public:
    int fibo(vector <int> &dp,int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fibo(dp,n-1)+fibo(dp,n-2);
    }
    int fib(int n) {
        vector <int> dp(n+1,-1);
        return fibo(dp,n);
    }
};