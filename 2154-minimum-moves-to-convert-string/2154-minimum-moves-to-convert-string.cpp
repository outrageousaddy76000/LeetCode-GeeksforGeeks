class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;){
            if(s[i]=='X'){
                ans++;
                i+=2;
            }
            i++;
        }
        return ans;
    }
};