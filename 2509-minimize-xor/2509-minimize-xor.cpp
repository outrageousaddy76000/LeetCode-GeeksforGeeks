class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        bitset <32> b(num1);
        int ans=0;
        for(int i=31;i>=0;i--){
            if(b[i]){
                ans+=(1<<i);
                cnt--;
            }
            if(cnt==0) break;
        }
        int i=0;
        while(cnt--){
            while((ans & (1<<i))) i++;
            ans+=(1<<i);           
        }
        return ans;
    }
};