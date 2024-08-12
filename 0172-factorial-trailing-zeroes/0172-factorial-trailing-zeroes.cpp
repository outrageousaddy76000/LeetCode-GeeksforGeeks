class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i+=5){
            int cnt=0;
            int temp = i;
            //how many times can we divide by 5
            while(temp%5==0){
                ans++;
                temp/=5;
            }
        }
        return ans;
    }
};