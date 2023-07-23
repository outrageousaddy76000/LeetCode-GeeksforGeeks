class Solution {
public:
    string thousandSeparator(int n) {
        //add a dot after every 3 digits
        string s=to_string(n);
        string ans="";
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            cnt++;
            ans+=s[i];
            if(cnt==3 && i!=0){
                ans+='.';
                cnt=0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};