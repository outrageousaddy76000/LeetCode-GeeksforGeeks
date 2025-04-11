class Solution {
private:
    vector<int> helper(vector <vector<int>> &dp, vector <int> &nums, int index){
        if(dp[index].size()) return dp[index];
        vector <int> ans;
        for(int i=index-1;i>=0;i--){
            if(nums[index]%nums[i]==0){
                vector <int> curr = helper(dp,nums,i);
                if(ans.size()<curr.size()) ans=curr;
            }
        }
        ans.push_back(nums[index]);
        return dp[index]=ans;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector <vector<int>> dp(n);
        sort(nums.begin(),nums.end());
        vector <int> ans=helper(dp,nums,n-1);
        for(int i=0;i<n-1;i++){
            vector <int> curr=helper(dp,nums,i);
            if(curr.size()>ans.size()) ans=curr;
        }
        return ans;
    }
};