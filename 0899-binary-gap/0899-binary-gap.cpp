class Solution {
public:
    int binaryGap(int n) {
        if(n==0 || (n&(n-1))==0){
            return 0;
        }
        bitset <32> s(n);
        vector <int> v;
        for(int i=0;i<32;i++){
            if(s[i]==1) v.push_back(i);
        }
        int ans=0;
        for(int i=1;i<v.size();i++){
            ans=max(abs(v[i]-v[i-1]),ans);
        }
        return ans;
    }
};