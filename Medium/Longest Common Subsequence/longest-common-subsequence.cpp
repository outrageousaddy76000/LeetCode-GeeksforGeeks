//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    int x,y;
    public:
    vector <vector <int>> dp;
    //Function to find the length of longest common subsequence in two strings.
    int helper(int n,int m,const string &s1,const string &s2){
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(n>=x || m>=y) return dp[n][m]=0;
        if(s1[n]==s2[m]){
            return dp[n][m] = 1 + helper(n+1,m+1,s1,s2);
        }
        else{
            int a = helper(n+1,m,s1,s2);
            int b = helper(n,m+1,s1,s2);
           
            return dp[n][m]=max(a,b); 
        }
    }
    int lcs(int n, int m, string s1, string s2){
        x=s1.size();
        y=s2.size();
        dp.resize(n+1,vector <int> (m+1,-1));
        return helper(0,0,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends