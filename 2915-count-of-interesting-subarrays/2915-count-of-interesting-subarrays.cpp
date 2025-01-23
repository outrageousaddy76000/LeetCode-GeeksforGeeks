class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        for(auto &val:nums){
            if(val%modulo==k) val=1;
            else val=0;
        }
        vector <long long int> pref(n);
        for(int i=0;i<n;i++){
            if(i) pref[i]=pref[i-1]+nums[i];
            else pref[i]=nums[i];
            pref[i]%=modulo;
        }
        for(auto &val:pref) cout<<val<<" ";
        cout<<endl;
        map <long long int,long long int> m;
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