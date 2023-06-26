class Solution {
public:
    bool checkRecord(string s) {
        int cnta=0,late=0,len=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='A') cnta++;
            if(cnta==2) return false;
            if(s[i]=='L'){
                len++;
            }
            else{
                late=max(len,late);
                len=0;
            }
        }
        late = max(len,late);
        if(late>=3) return false;
        return true;
    }
};