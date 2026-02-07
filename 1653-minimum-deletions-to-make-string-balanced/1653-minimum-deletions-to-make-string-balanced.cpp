class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector <int> pref(n);
        for(int i=0;i<n;i++){
            if(i) pref[i]=pref[i-1]+(s[i]=='a'? 1:0);
            else pref[i]=(s[i]=='a'? 1:0);
        }
        int ans=pref[n-1];
        for(int i=0;i<n;i++){
            ans=min(ans,(i+1)-pref[i]+pref[n-1]-pref[i]);
        }
        return ans;
    }
};