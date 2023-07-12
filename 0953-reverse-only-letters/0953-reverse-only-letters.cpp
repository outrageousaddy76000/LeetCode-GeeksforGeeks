class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans="";
        string letters="";
        queue <int> qu;
        for(int i=0;i<s.size();i++){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                letters+=s[i];
            }
            else qu.push(i);
        }
        reverse(letters.begin(),letters.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(qu.front()==i){
                ans+=s[i];
                qu.pop();
            }
            else{
                ans+=letters[j];
                j++;
            }
        }
        return ans;
    }
};