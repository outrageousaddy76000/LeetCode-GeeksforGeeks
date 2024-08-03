class Solution {
public:
    bool check(string &s1, string &s2){
        string ans1="",ans2="";
        for(char &ch:s1) if(ch!='X') ans1+=ch;
        for(char &ch:s2) if(ch!='X') ans2+=ch;
        return ans1==ans2;
    }
    bool canTransform(string start, string end) {
        //just swap and check
        //remove all x and check if same
        if(!check(start,end)) return false;
        int n = start.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(start[i]=='R') cnt++;
            if(end[i]=='R') cnt--;
            if(cnt<0) return false;
        }
        cnt=0;
        for(int i=n;i>=0;i--){
            if(start[i]=='L') cnt++;
            if(end[i]=='L') cnt--;
            if(cnt<0) return false;
        }
        return true;
    }
};