class Solution {
private:
    vector <long long int> dp;
    long long helper(int index, vector <long long> &dp, vector <vector<int>> &v){
        if(index>=v.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        //choose the ith index
        long long ans1 = v[index][0]+helper(index+v[index][1]+1, dp, v);
        //dont choose the ith index
        long long ans2 = helper(index+1,dp,v);
        return dp[index]=max(ans1,ans2);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(),-1);
        return helper(0,dp,questions);
    }
};