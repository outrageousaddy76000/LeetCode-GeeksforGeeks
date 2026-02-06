class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            long long int search = 1LL*nums[i]*k;
            auto it = upper_bound(nums.begin(),nums.end(), search);
            int rem = i + nums.end()-it;
            ans=min(rem,ans);
        }
        return ans;
    }
};