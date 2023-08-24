class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3) return 0;
        unordered_map <char,int> m;
        int ans = 0;
        m[s[0]]++;
        m[s[1]]++;
        m[s[2]]++;
        for(int i=3;i<s.size();i++){
            if(m.size()==3) ans++;
            m[s[i-3]]--;
            if(m[s[i-3]]==0) m.erase(s[i-3]);
            m[s[i]]++;
        }
        if(m.size()==3) ans++;
        return ans;
    }
};