class Solution {
public:
    string sortString(string s) {
        int j=0;
        vector <int> v(26);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        string ans="";
        while(1){
            string a =ans;
            if(j%2==0){
                for(int i=0;i<26;i++){
                    if(v[i]>0){
                        ans+=('a' + i);
                        v[i]--;
                    }
                }
            }
            else{
                for(int i=25;i>=0;i--){
                    if(v[i]>0){
                        ans+=('a' + i);
                        v[i]--;
                    }
                }
            }
            j++;
            if(a==ans) break;
        }
        return ans;
    }
};