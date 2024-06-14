class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int curr=nums[0]-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>curr){
                curr = nums[i];
            }
            else{
                //increment ans to make it greater than curr
                ans+= curr+1 - nums[i];
                curr++;
            }
        }
        return ans;
    }
};