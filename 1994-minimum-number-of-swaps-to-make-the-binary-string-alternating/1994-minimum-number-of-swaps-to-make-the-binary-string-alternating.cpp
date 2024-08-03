class Solution {
public:
    int minSwaps(string s) {
        int c0=0,c1=0;
        int n = s.size();
        string a = "0";
        for(int i=0;i<n;i++){
            if(s[i]=='0') c0++;
            else c1++;
            if(i){
                if(a[i-1]=='0') a+="1"; else a+="0";
            }
        }
        if(abs(c0-c1)>1) return -1;
        if(c0==c1){
            //check both
            int cnt1=0,cnt2=0;
            for(int i=0;i<n;i++) if(s[i]!=a[i]) cnt1++;
            for(int i=0;i<n;i++) if(s[i]==a[i]) cnt2++;
            return (min(cnt1,cnt2))/2;
        }
        else if(c0>c1){
            //only 01010...
            int cnt1=0;
            for(int i=0;i<n;i++) if(s[i]!=a[i]) cnt1++;
            return (cnt1+1)/2;
        }
        int cnt1=0;
        for(int i=0;i<n;i++) if(s[i]==a[i]) cnt1++;
        return (cnt1+1)/2;
    }
};