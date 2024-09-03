class Solution {
public:
    void change(string &s){
        int x=0;
        for(int i=0;i<s.size();i++){
            x+=s[i]-'0';
        }
        s=to_string(x);
    }
    int getLucky(string s, int k) {
        string a = "";
        for(int i=0;i<s.size();i++){
            a+=to_string(s[i]-'a' + 1 );
        }
        for(int i=0;i<k;i++){
            change(a);
        }
        return stoi(a,0,10);
    }
};