//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    const int mod = 1e9+7;
    long long int helper(int n,vector <long long int> &dp){
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(helper(n-1,dp)%mod+helper(n-2,dp)%mod)%mod;
    }
    int nthFibonacci(int n){
        vector <long long int> dp(n+1,-1);
        dp[0]=0,dp[1]=1;
        return helper(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends