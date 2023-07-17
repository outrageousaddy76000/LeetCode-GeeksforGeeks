//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    int solve(int i,int j,string s1,string s2, vector<vector<int>>&dp){
        if(i<0||j<0)return 0;
        
        if(s1[i]==s2[j] && i!=j){
           return dp[i][j]= 1+solve(i-1,j-1,s1,s2,dp);
        }
        else{
            return dp[i][j]=  max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
        }
        
    }
    int LongestRepeatingSubsequence(string str){
        int n=str.size();
        string s2=str;
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=n;j++){
                
                if(str[i-1]==s2[j-1] && i!=j){
                               curr[j]= 1+next[j-1];
            }
                        else{
                                curr[j]=  max(next[j],curr[j-1]);
                      } 
                
                
            }
            next=curr;
        }
        
        return next[n];
    }
     
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends