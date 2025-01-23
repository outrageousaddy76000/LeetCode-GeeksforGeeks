class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
        int ans=0;
        unordered_map <int,int> m;
        for(int i=0;i<n;i++){
            if(nums[i]&1) cnt++;
            nums[i]=cnt;
            if(m.find(nums[i]-k)!=m.end()){
                ans+=m[nums[i]-k];
            }
            if(nums[i]==k) ans++;
            m[nums[i]]++; 
        }
        return ans;
    }
};