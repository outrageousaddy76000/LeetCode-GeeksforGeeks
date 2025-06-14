class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char c;
        for(int i=0;i<s.size();i++){
            if(s[i]!='9'){
                c=s[i];
                break;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==c) s[i]='9';
        }
        int x = stoi(s,0,10);
        s = to_string(num);
        c=s[0];
        for(int i=0;i<s.size();i++){
            if(s[i]==c) s[i]='0';
        }
        int y = stoi(s,0,10);
        return x-y;
    }
};