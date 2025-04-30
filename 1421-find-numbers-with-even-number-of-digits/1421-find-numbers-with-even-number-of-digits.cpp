class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int j=1;
            while(1){
                int x = nums[i]/pow(10,j);
                if(x==0){
                    if(j%2==0) ans++;
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};