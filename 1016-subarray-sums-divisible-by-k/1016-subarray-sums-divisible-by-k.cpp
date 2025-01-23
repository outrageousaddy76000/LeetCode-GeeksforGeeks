class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
        int ans=0;
        unordered_map <int,int> m;
        for(int i=0;i<n;i++){
            if(i) nums[i]+=nums[i-1];
            nums[i]%=k;
            nums[i]+=k;
            nums[i]%=k;
            if(m.find(nums[i])!=m.end()){
                ans+=m[nums[i]];
            }
            if(nums[i]==0) ans++;
            m[nums[i]]++; 
        }
        return ans;
    }
};