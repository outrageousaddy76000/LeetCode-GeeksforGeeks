class Solution {
public:
    string modifyString(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                if(i==0){
                    if(s[i+1]=='a') s[i]='b';
                    else s[i]='a';
                }
                else if(i==s.size()-1){
                    if(s[i-1]=='a') s[i]='b';
                    else s[i]='a';
                }
                else{
                    if(s[i-1]!='a' && s[i+1]!='a') s[i]='a';
                    else if(s[i-1]!='b' && s[i+1]!='b') s[i]='b';
                    else s[i]='c';
                }
            }
        }
        return s;
    }
};