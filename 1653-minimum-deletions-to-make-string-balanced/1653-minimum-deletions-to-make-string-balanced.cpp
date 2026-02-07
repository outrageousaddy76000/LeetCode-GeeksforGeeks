class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cnt_a=0;
        for(int i=0;i<n;i++){
            cnt_a+=(s[i]=='a'? 1:0);
        }
        int ans=cnt_a;
        int curr_a=0;
        for(int i=0;i<n;i++){
            curr_a+=(s[i]=='a'? 1:0);
            ans=min(ans,(i+1)-2*curr_a+cnt_a);
        }
        return ans;
    }
};