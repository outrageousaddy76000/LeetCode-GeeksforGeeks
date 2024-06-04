class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.push_back(INT_MIN);
        for(int i=0;i<nums.size()-1;i++){
            if(i){
                if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
            }
            else if(nums[i]>nums[i+1]) return i;
        }
        return 0;
    }
};