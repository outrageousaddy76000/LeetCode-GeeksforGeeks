class Solution {
public:
    bool checkZeroOnes(string s) {
        int ans1=0,ans2=0;
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            cout<<cnt1<<" "<<cnt2<<" "<<endl;
            if(i){
                if(s[i]==s[i-1]){
                    if(s[i]=='1') cnt1++;
                    else cnt2++;
                }
                else{
                    if(s[i-1]=='1') ans1=max(ans1,cnt1);
                    else ans2 = max(cnt2,ans2);
                    if(s[i]=='1'){
                        cnt2=0,cnt1=1;
                    }
                    else{
                        cnt2=1,cnt1=0;
                    }
                }
            }
            else{
                if(s[i]=='1') cnt1++;
                else cnt2++;
            }
        }
        ans1=max(cnt1,ans1);
        ans2=max(cnt2,ans2);
        cout<<ans1<<" "<<ans2;
        return ans1>ans2;
    }
};