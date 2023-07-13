class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size() && nums[i]<=0){
            nums[i]*=-1;
            k--;
            i++;
            if(k==0) break;
        }
        sort(nums.begin(),nums.end());
        if(k%2==0){
            return accumulate(nums.begin(),nums.end(),0);
        }
        else{
            nums[0]*=-1;
            return accumulate(nums.begin(),nums.end(),0);
        }
    }
};