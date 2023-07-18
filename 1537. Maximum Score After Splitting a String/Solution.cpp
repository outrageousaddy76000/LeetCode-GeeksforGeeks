class Solution {
public:
    int maxScore(string s) {
        vector <int> v(s.size()-1);
        int cnt=0;
        int x = count(s.begin(),s.end(),'1');
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                cnt++;
            }
            v[i]=cnt+ x-(i+1-cnt);
        }
        return *max_element(v.begin(),v.end());
    }
};