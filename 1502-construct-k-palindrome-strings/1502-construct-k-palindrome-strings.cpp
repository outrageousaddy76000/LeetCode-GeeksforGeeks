class Solution {
public:
    bool canConstruct(string s, int k) {
        vector <int> freq(26);
        for(char &c:s) freq[c-'a']++;
        int cnt=0;
        for(int &x:freq) (x&1)?cnt++:0;
        cout<<cnt;
        return cnt<=k && (s.size()-cnt)>=k-cnt;
    }
};