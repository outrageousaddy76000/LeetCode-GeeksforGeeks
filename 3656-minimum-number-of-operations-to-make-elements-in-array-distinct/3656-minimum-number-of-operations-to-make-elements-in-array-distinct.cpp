class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        unordered_map <int,int> m;
        int ans=0;
        for(auto &val:nums){
            m[val]++;
        }
        for(int i=nums.size()-1;i>=0;i-=3){
            if(m.size()==i+1) return ans;
            if(i>=2){
                m[nums[i]]--;
                if(m[nums[i]]==0) m.erase(nums[i]);
                m[nums[i-1]]--;
                if(m[nums[i-1]]==0) m.erase(nums[i-1]);
                m[nums[i-2]]--;
                if(m[nums[i-2]]==0) m.erase(nums[i-2]);
            }
            ans++;
        }
        return ans;
    }
};