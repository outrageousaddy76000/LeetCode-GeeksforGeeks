class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector <int> pref(n);
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k) nums[i]=1;
            else nums[i]=0;
            if(i) pref[i]=pref[i-1]+nums[i];
            else pref[i]=nums[i];
            pref[i]%=modulo;
        }
        map <int,int> m;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(m.find(((pref[i]-k)%modulo + modulo)%modulo)!=m.end()){
                ans+=m[(((pref[i]-k)%modulo + modulo)%modulo)];
            }
            if(pref[i]%modulo==k) ans++;
            m[pref[i]]++; 
        }
        return ans;
    }
};