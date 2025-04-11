class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        int mini=INT_MAX;
        for(auto &val:nums){
            m[val]++;
            if(val<k) return -1;
        }
        if(m.find(k)!=m.end()) return m.size()-1;
        return m.size();
    }
};