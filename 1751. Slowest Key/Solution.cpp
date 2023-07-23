class Solution {
public:
    char slowestKey(vector<int>& v, string s) {
        int ans=v[0];
        char final=s[0];
        for(int i=0;i<s.size();i++){
            if(i){
                if(v[i]-v[i-1]>ans){
                    ans=v[i]-v[i-1];
                    final=s[i];
                }
                else if(v[i]-v[i-1]==ans){
                    final=max(s[i],final);
                }
            }
        }
        return final;
    }
};