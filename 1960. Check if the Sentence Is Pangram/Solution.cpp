class Solution {
public:
    bool checkIfPangram(string s) {
        vector <int> v(26);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(!v[i]) return false;
        }
        return true;
    }
};