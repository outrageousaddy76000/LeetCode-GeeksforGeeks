class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //sliding window
        int ans=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                cnt++;
            }
            else{
                if(nums[i]>nums[i-1]){
                    cnt++;
                }
                else{
                    ans=max(ans,cnt);
                    cnt=1;
                }
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};