class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> ans(nums.size());
        vector <int> pre(101);
        for(int i=0;i<nums.size();i++){
            pre[nums[i]]++;
        }
        for(int i=1;i<pre.size();i++){
            pre[i]+=pre[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                ans[i]=pre[nums[i]-1];
            else ans[i]=0;
        }
        return ans;
    }
};