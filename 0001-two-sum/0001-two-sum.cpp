class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // just 2 loops or we could have sorted and used sliding window for nlogn instead of n^2
        vector <int> v(2);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    v[0]=i;
                    v[1]=j;
                }
            }
        }
        return v;
    }
};