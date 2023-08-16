class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0,prev=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1' && !prev){
                cnt++;
                prev=1;
            }
            else if(s[i]=='0'){
                prev=0;
            }
        }
        cout<<cnt;
        return cnt<=1;
    }
};