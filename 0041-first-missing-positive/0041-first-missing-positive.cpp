class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        if(j==0) return 1;
        // j is the important length of the array
        for(int i=0;i<j;i++){
        int k=abs(nums[i]);
            if(k<=j)
                nums[k-1]=(nums[k-1]<0)?nums[k-1]:-nums[k-1];
        }
        for(int i=0;i<j;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return j+1;
    }
};