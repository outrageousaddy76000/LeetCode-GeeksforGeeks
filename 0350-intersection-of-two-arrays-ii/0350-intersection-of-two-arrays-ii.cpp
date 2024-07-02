class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> m1,m2;
        vector <int> ans;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]++;
        }
        for(auto &pr:m1){
            for(int i=0;i<min(pr.second,m2[pr.first]);i++)
            ans.push_back(pr.first);
        }
        return ans;
    }
};