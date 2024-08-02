class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //count the number of 1s
        int x = count(nums.begin(),nums.end(),1);
        //find the max number of 1s currently present in any subarray of length 5
        int maxcnt=0,cnt=0;
        for(int i=0;i<x;i++){
            if(nums[i]==1) cnt++;
            maxcnt=max(cnt,maxcnt);
        }
        //we have done for 0 to x, now we consider start from 1 to (n-1)th index
        for(int i=1;i<nums.size();i++){
            //starts at i
            if(nums[i-1]==1) cnt--;
            if(nums[(i+x-1)%nums.size()]==1) cnt++;
            maxcnt = max(cnt,maxcnt);
        }
        return x-maxcnt;
    }
};