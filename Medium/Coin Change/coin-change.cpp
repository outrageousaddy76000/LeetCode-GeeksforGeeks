//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector <vector<long long int>> dp;
    int n;
    long long int helper(int target,int m,int coins[]){
        if(dp[target][m]!=-1){
            return dp[target][m];
        }
        if(m>=n || target<0) return dp[target][m]=0;
        if(target==0) return dp[target][m]=1;
        if(target<coins[m]){
            return dp[target][m]=0;
        }
        if(target==coins[m]){
            long long int b = helper(target,m+1,coins);
            return dp[target][m]=1+b;
        }
        else{
            long long int a = helper(target-coins[m],m,coins);
            long long int b = helper(target,m+1,coins);
            return dp[target][m]=a+b;
        }
    }
    long long int count(int coins[], int a, int target) {
        //unbound knapsack
        n = a;
        sort(coins,coins+n);
        dp.resize(target+1,vector <long long int> (n+1,-1));
        return helper(target,0,coins);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends