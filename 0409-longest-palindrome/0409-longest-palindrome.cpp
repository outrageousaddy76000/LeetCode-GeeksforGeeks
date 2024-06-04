class Solution {
public:
    int longestPalindrome(string s) {
        //largest odd freq + all other odd freq-1 + all even freq
        unordered_map <char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int ans=0,check=0;
        for(auto &pr:m){
            if(pr.second%2==0){
                ans+=pr.second;
            }
            else{
                ans+=pr.second-1;
                check=1;
            }
        }
        if(check) ans++;
        return ans;
    }
};