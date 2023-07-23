class Solution {
public:
    string makeGood(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(i && ans.size()){
                if(s[i]!=ans[ans.size()-1] && (tolower(s[i])==ans[ans.size()-1] || tolower(ans[ans.size()-1])==s[i])){
                    ans.pop_back();
                    continue;
                }
            }
            ans+=s[i];
        }
        return ans;
    }
};