class Solution {
public:
    bool isvowel(char c){
        c=tolower(c);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<s.size();i++){
            if(i<s.size()/2){
                if(isvowel(s[i])) cnt1++;
            }
            else{
                if(isvowel(s[i])) cnt2++;
            }
        }
        return cnt1==cnt2;
    }
};