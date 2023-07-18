class Solution {
public:
    string reformat(string s) {
        int cnt=0;
        int n = s.size();
        string ans="";
        string num="";
        string alpha="";
        for(int i=0;i<n;i++){
            if(s[i]<58){
                num+=s[i];
                cnt++;
            }
            else alpha+=s[i];
        }
        if (abs(static_cast<int>(cnt - (n - cnt))) > 1) return ans;
        if(cnt>n-cnt){
            int i=0;
            while(1){
                ans+=num[i];
                n--;
                if(n==0) break;
                ans+=alpha[i];
                n--;
                if(n==0) break;
                i++;
            }
        }
        else{
            int i=0;
            while(1){
                ans+=alpha[i];
                n--;
                if(n==0) break;
                ans+=num[i];
                n--;
                if(n==0) break;
                i++;
            }
        }
        return ans;
    }
};