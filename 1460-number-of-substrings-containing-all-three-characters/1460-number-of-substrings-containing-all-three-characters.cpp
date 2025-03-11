class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int n = s.size();
        int ans=0;
        vector <int> v(3);
        while(i<n){
            //for each i, what will be the answer
            while((v[0]<=0 || v[1]<=0 || v[2]<=0) && j<n){
                v[s[j]-'a']++;
                j++;
            }
            if(j==n && (v[0]==0 || v[1] ==0 || v[2]==0) ) break;
            //increase the ans
            ans+=n-j+1;
            v[s[i]-'a']--;
            i++;
        }
        return ans;
    }
};