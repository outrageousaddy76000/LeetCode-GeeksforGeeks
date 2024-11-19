class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int ans=0;
        unordered_map <int,int> m;
        long long int sum=0;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
            sum+=nums[i];
        }
        if(m.size()==k) ans=max(sum,ans);
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];
            m[nums[i-k]]--;
            m[nums[i]]++;
            if(m[nums[i-k]]==0) m.erase(nums[i-k]);
            if(m.size()==k) ans=max(sum,ans);
        }
        return ans;
    }
};