class Solution {
public:
    int maxelem(multiset <int> &s){
        return *s.rbegin();
    }
    int minelem(multiset <int> &s){
        return *s.begin();
    }
    int longestSubarray(vector<int>& nums, int limit) {
        multiset <int> s;
        int ans=1;
        int i=0,j=0;
        while (j<nums.size()){
            s.insert(nums[j]);
            while (maxelem(s) - minelem(s) > limit) {
                s.erase(s.find(nums[i]));
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};