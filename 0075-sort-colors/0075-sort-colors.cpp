class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j=0;
        int k=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        for(int i=nums.size()-1;i>=j;i--){
            if(nums[i]==2){
                swap(nums[i],nums[k]);
                k--;
            }
        }
    }
};