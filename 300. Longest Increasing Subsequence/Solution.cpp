class Solution {
public:    
    int helper(int n,vector <int> &arr,vector <int> &dp){
        if(dp[n]!=-1) return dp[n];
        //all numbers that are smaller than arr[n] from index 0 to n-1;
        int ans=0;
        for(int i=0;i<=n-1;i++){
            if(arr[i]<arr[n])
            ans=max(helper(i,arr,dp),ans);
        }
        return dp[n]=++ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n+1,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(helper(i,nums,dp),ans);
        }
        return ans;
    }
};