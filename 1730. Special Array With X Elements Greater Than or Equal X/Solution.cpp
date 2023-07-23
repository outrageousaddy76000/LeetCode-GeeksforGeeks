class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<=nums[nums.size()-1];i++){
            auto it = lower_bound(nums.begin(),nums.end(),i);
            int dist = nums.end()-it;
            if(dist==i) return i;
        }
        return -1;
    }
};