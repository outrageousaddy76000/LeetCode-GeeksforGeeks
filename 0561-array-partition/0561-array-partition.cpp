class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n = nums.size()/2;
        for(int i=0;i<2*n;i+=2){
            ans+=min(nums[i],nums[i+1]);
        }
        return ans;
    }
};