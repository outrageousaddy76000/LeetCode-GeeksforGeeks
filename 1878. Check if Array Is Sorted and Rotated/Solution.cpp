class Solution {
public:
    bool check(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<0){
                cnt++;
                if(nums[i-1]!=maxi) return false;
            }
        }
        return cnt==0 ||(cnt && nums[0]>=nums[n-1]);
    }
};