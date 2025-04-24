class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map <int,int> m;
        int j=-1,i=0;
        set <int> s(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            while(j+1<nums.size() && (m.size()!=s.size())){
                j++;
                m[nums[j]]++;
            }
            if(m.size()==s.size()) ans+=nums.size()-j;
            else break;
            m[nums[i]]--;
            if(m[nums[i]]==0) m.erase(nums[i]);
        }
        return ans;
    }
};