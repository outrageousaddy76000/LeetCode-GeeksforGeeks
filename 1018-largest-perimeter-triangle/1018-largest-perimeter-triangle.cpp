class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        int z = n-1;
        int x,y;
        int check=0;
        for(;z>=2;z--){
            x=z-1,y=z-2;
            while(y>=0){
                if(nums[x--]+nums[y--]>nums[z]){
                    ans=nums[x+1]+nums[y+1]+nums[z];
                    check=1;
                    break;
                }
            }
            if(check) break;
        }
        return ans;
    }
};