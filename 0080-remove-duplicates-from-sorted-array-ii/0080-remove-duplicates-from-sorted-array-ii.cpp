class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int freq_count=0, last=-1, curr_index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==last){
                freq_count++;
            }
            else{
                freq_count=1;
                last=nums[i];
            }
            if(freq_count<=2){
                swap(nums[i],nums[curr_index++]);
            }
        }
        return curr_index;
    }
};