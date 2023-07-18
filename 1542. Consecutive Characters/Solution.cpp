class Solution {
public:
    int maxPower(string s) {
        //longest repeating
        int cnt=1;
        int ans=INT_MIN;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};