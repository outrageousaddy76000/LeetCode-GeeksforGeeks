class Solution {
public:
    int appendCharacters(string s, string t) {
        //find how long it contains
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[curr]) curr++;
        }
        return t.size()-curr;
    }
};