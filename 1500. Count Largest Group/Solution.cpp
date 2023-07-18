class Solution {
public:
    int getDigits(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map <int,int> m;
        for(int i=1;i<=n;i++){
            m[getDigits(i)]++;
        }
        int maxi=INT_MIN;
        for(auto &pr:m){
            int x = pr.second;
            maxi= max(maxi,x);
        }
        int ans=0;
        for(auto &pr:m){
            if(pr.second==maxi) ans++;
        }
        return ans;
    }
};