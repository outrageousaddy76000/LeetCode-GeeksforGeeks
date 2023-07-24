class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans=0;
        int n = sequence.size();
        int cnt;
        for(int i=0;i<n;i++){
            cnt=0;
            if(sequence.substr(i,word.size())==word){
                int x=i+word.size();
                cnt++;
                while(sequence.substr(x,word.size())==word){
                    cnt++;
                    x+=word.size();
                }
                ans=max(ans,cnt);
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};