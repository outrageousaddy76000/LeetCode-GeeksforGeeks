class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n>0){
            int x=3;
            x&=n;
            if(x==3 || x==0) return false;
            n>>=1;
        }
        return true;
    }
};