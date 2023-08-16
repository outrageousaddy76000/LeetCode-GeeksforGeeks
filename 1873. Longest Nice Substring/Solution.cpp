class Solution {
public:
    bool nice(string s){
        //if both uppercase and lowercase occur, its nice
        vector <int> a(26),b(26);
        for(int i=0;i<s.size();i++){
            if(s[i]<97){
                a[s[i]-'A']++;
            }
            else{
                b[s[i]-'a']++;
            }
        }
        for(int i=0;i<a.size();i++){
            if((a[i]>0 && b[i]==0) || (a[i]==0 && b[i]>0)) return false;
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string a=s.substr(i,j-i+1);
                if(nice(a)){
                    if(a.size()>ans.size()) ans=a;
                }
            }
        }
        return ans;
    }
};