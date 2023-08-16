class Solution {
public:
    int minOperations(string s) {
        int cnt=0;
        int ans1=0,ans2=0;
        for(int i=0;i<s.size();i++){
            if(cnt==0){
                if(s[i]=='1') ans1++;
                else ans2++;
                cnt=1;
            }
            else{
                if(s[i]=='1') ans2++;
                else ans1++;
                cnt=0;
            }
        }
        return min(ans1,ans2);
    }
};