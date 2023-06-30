class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int cnt1=0,cnt2=0;
        int j=0;
        int k=n-1;
        while(k>j){
            if(s[j]!=s[k]){
                cnt1++;
                k--;
            }
            else{
                j++;
                k--;
            }
        }
        j=0;
        k=n-1;
        while(k>j){
            if(s[j]!=s[k]){
                cnt2++;
                j++;
            }
            else{
                j++;
                k--;
            }
        }
        return min(cnt1,cnt2)<2;
    }
};