class Solution {
public:
    string interpret(string s) {
        string ans="";
        int n = s.size();
        for(int i=0;i<n;){
            if(s[i]=='G'){
                ans+='G';
                i++;
            }
            else if(s[i]=='(' && s[i+1]==')'){
                ans+='o';
                i+=2;
            }
            else{
                ans+="al";
                i+=4;
            }
        }
        return ans;
    }
};