class Solution {
public:
    int solve(int index, vector <int> &arr, int &k, vector <int> &dp){
        //take max
        if(index>=arr.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int maxi = 0;
        int ans=0;
        for(int i=0;i<k;i++){
            //call recursion for each
            if(index+i>=arr.size()) break;
            maxi = max(arr[index+i],maxi);
            ans = max(ans,maxi*(i+1) + solve(index+i+1,arr,k,dp));
        }
        return dp[index]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector <int> dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};