class Solution {
public:
    string compressedString(string word) {
        string ans="";
        string curr="";
        for(int i=0;i<word.size();i++){
            if(curr.size()==9 || (curr.size() && word[i]!=curr[curr.size()-1])){
                ans+=(curr.size()+48);
                ans+=curr[curr.size()-1];
                curr=word[i];
            }
            else curr+=word[i];
        }
        if(curr.size()){
            ans+=(curr.size()+48);
            ans+=curr[curr.size()-1];
        }
        return ans;
    }
};