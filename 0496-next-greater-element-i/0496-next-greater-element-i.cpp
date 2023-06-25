class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        unordered_map <int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
        }
        for(int i=0;i<nums1.size();i++){
            int x = nums1[i];
            int check=0;
            int indexin2 = m[nums1[i]];
            for(int j=indexin2+1;j<nums2.size();j++){
                if(nums2[j]>x){
                    ans.push_back(nums2[j]);
                    check=1;
                    break;
                }
            }
            if(!check) ans.push_back(-1);
        }
        return ans;
    }
};