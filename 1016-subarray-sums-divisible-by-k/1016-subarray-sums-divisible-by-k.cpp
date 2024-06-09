class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        int ans=0;
        map <int,int> m;
        for(int i=0;i<n;i++){
            if(i) sum+=nums[i];
            else sum=nums[i];
            sum%=k;
            sum+=k;
            sum%=k;
            if(sum%k==0) ans++;
            if(m.find(sum)!=m.end()) ans+=m[sum];
            m[sum]++;
        }
        return ans;
    }
};