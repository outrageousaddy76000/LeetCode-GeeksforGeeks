class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int tot = accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend());
        vector <int> ans;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans.push_back(nums[i]);
            if(sum>tot-sum) break;
        }
        return ans;
    }
};