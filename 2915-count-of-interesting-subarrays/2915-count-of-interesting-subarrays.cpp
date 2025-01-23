class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k) cnt++;
            nums[i]=cnt;
            nums[i]%=modulo;
        }
        map <int,int> m;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(m.find(((nums[i]-k)%modulo + modulo)%modulo)!=m.end()){
                ans+=m[(((nums[i]-k)%modulo + modulo)%modulo)];
            }
            if(nums[i]%modulo==k) ans++;
            m[nums[i]]++; 
        }
        return ans;
    }
};