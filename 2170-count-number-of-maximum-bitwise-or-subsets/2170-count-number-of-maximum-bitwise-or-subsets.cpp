class Solution {
public:
    int ans,maxor;
    void helper(vector <int> &nums, int index, int curror){
        if (curror == maxor) ans++;

        for (int i = index; i < nums.size(); ++i){
            helper(nums, i + 1, curror | nums[i]);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        maxor=0;
        ans=0;
        for(auto &val:nums) maxor|=val;
        helper(nums,0,0);
        return ans;
    }
};