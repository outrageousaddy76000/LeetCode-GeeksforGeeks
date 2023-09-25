class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map <char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        m[t[s.size()]]--;
        for(auto &pr:m){
            if(pr.second<0) return pr.first; 
        }
        return 'x';
    }
};