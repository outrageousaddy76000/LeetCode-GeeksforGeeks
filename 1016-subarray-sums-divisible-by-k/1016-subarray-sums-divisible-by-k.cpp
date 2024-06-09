class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> pre(n);
        int ans=0;
        map <int,int> m;
        for(int i=0;i<n;i++){
            if(i) pre[i]=pre[i-1]+nums[i];
            else pre[i]=nums[i];
            pre[i]%=k;
            pre[i]+=k;
            pre[i]%=k;
            if(pre[i]%k==0) ans++;
            if(m.find(pre[i])!=m.end()) ans+=m[pre[i]];
            m[pre[i]]++;
        }
        return ans;
    }
};