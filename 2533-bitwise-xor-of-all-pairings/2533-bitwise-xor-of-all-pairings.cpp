class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(auto &val:nums1) if(nums2.size()&1) ans^=val;
        for (auto &val:nums2) if(nums1.size()&1) ans^=val;
        return ans;
    }
};