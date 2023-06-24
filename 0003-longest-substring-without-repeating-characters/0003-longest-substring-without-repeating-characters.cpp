class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> m;
        int ans=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            int x = m.size();
            m[s[j]]++;
            int y = m.size();
            if(x==y){
                //repeated
                char rem = s[j];
                while(s[i]!=rem){
                    m.erase(s[i]);
                    i++;
                }
                m[s[i]]--;
                i++;
            }
            int b = m.size();
            ans = max(ans,b);
        }
        return ans;
    }
};