class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        int mini=INT_MAX;
        for(auto &val:nums){
            m[val]++;
            mini=min(mini,val);
        }
        if(k>mini) return -1;
        else if(k==mini) return m.size()-1;
        else return m.size();
    }
};