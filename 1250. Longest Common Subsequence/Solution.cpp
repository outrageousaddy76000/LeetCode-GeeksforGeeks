class Solution {
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
    int longestCommonSubsequence(string s1, string s2) {
        x=s1.size();
        y=s2.size();
        dp.resize(x+1,vector <int> (y+1,-1));
        return helper(0,0,s1,s2);
    }
};