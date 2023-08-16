class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curr=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i){
                if(nums[i]>nums[i-1]){
                    curr+=nums[i];
                }
                else {
                    ans=max(ans,curr);
                    curr=nums[i];
                }
            }
            else{
                curr+=nums[i];
            }
        }
        ans=max(ans,curr);
        return ans;
    }
};