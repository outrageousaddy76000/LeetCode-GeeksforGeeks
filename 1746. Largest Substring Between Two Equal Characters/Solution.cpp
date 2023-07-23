class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=-1;
        for(int i=0;i<s.size();i++){
            for(int j=s.size()-1;j>i;j--){
                if(s[j]==s[i]){
                    ans=max(ans,j-i-1);
                    break;
                }
            }
        }
        return ans;
    }
};