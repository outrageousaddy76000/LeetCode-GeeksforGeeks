class Solution {
public:
    string replaceDigits(string s) {
        for(int i=1;i<s.size();i++){
            if(s[i]>='a') continue;
            char c = s[i-1];
            s[i]=c + s[i]-'1'+1;
        }
        return s;
    }
};