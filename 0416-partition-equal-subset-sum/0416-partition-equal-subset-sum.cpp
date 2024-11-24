class Solution {
private:
    vector <vector<int>> dp;
    bool solve(int index, vector <int> &nums, int sum, int curr){
        if(index==nums.size()){
            if(curr==sum/2) return true;
            return false;
        }
        if(dp[index][curr]!=-1) return dp[index][curr];
        //take the current index
        bool ans=false;
        if(nums[index]+curr<=sum/2)
        ans|= solve(index+1,nums,sum,curr+nums[index]);
        ans|= solve(index+1,nums,sum,curr);
        return dp[index][curr]=ans;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        dp.resize(nums.size()+1,vector <int> (sum+1));
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                dp[i][j]=-1;
            }
        }
        if(sum&1) return false;
        return solve(0,nums,sum,0);
    }
};