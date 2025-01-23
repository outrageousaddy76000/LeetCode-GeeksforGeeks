class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int cnt=0;
        long long ans=0;
        map <int,int> m;
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k) cnt++;
            nums[i]=cnt;
            nums[i]%=modulo;
            if(m.find(((nums[i]-k)%modulo + modulo)%modulo)!=m.end()){
                ans+=m[(((nums[i]-k)%modulo + modulo)%modulo)];
            }
            if(nums[i]%modulo==k) ans++;
            m[nums[i]]++; 
        }
        return ans;
    }
};