class Solution {
public:
    int minimumLength(string s) {
        vector <int> v(26);
        int ans=0;
        for(auto &val:s) v[val-'a']++;
        for(auto &val:v) val==0?0:val&1?ans++:ans+=2;
        return ans; 
    }
};