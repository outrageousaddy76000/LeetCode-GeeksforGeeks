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
        vector <int> v(37);
        for(int i=1;i<=n;i++){
            v[getDigits(i)]++;
        }
        int maxi=*max_element(v.begin(),v.end());
        return count(v.begin(),v.end(),maxi);
    }
};