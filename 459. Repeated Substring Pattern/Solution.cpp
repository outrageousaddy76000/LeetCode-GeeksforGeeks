class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        unordered_map <char,int> m;
        int n = s.size();
        for(int i=1;i<=n/2;i++){
            if(n%i!=0) continue;
            int x = n/i;
            string a = s.substr(0,i);
            string check="";
            for(int j=0;j<x;j++){
                check+=a;
            }
            if(check==s){
                return true;
            }
        }
        return false;
    }
};