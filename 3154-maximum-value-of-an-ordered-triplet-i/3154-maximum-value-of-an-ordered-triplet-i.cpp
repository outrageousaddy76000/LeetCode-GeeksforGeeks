class Solution {
public:
    long long int max(long long int a,long long int b){
        if(a>b) return a;
        return b;
    }
    long long maximumTripletValue(vector<int>& nums) {
        long long int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    long long int val = 1LL*(nums[i] - nums[j])*nums[k];
                    ans=max(ans,val);
                }
            }
        }
        return max(ans,0);
    }
};