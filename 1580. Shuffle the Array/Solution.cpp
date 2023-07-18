class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans(nums.size());
        for(int i=0,j=0;i<nums.size()/2;i++,j+=2){
            ans[j]=nums[i];
        }
        for(int i=nums.size()/2,j=1;i<nums.size();i++,j+=2){
            ans[j]=nums[i];
        }
        return ans;
    }
};