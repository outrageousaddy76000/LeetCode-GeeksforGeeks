class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
        int ans=0;
        unordered_map <int,int> m;
        for(int i=0;i<n;i++){
            if(i) nums[i]=nums[i-1]+nums[i];
            if(m.find(nums[i]-k)!=m.end()){
                ans+=m[nums[i]-k];
            }
            if(nums[i]==k) ans++;
            m[nums[i]]++; 
        }
        return ans;
    }
};