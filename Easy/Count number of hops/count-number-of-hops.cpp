//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    const int mod = 1e9+7;
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long int helper(int n,vector <long long int> &dp){
        if(dp[n]!=-1) return dp[n];
        else return dp[n]=(helper(n-1,dp)+helper(n-2,dp)+helper(n-3,dp))%mod;
    }
    long long countWays(int n)
    {
        vector <long long int> dp(n+5,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        return helper(n,dp)%mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends