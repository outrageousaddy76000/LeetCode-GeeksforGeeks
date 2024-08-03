class Solution {
public:
    int minSwaps(string s) {
        //two pointer
        int ans=0;
        //swap first anomaly with last anomaly
        int n = s.size();
        int i=0,j=n-1;
        int cnt=0,cnt2=0;
        while(true){
            while(i<n){
                if(s[i]=='[') cnt++;
                else cnt--;
                if(cnt<0) break;
                i++;
            }
            while(j>=i){
                if(s[j]==']') cnt2++;
                else cnt2--;
                if(cnt2<0) break;
                j--;
            }
            if(j<=i) break;
            swap(s[i],s[j]);
            ans++;
            i++;j--;
            cnt=1;
            cnt2=1;
        }
        return ans;
    }
};