class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        if(nums2.size()&1) for(auto &val:nums1) ans^=val;
        if(nums1.size()&1) for (auto &val:nums2) ans^=val;
        return ans;
    }
};