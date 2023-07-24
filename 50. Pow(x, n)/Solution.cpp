class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int check=0,pos=0,neg=0;
        if(n<0) check=1;
        if(x<0){
            if(n%2==0) pos = 1;
            else neg=1;
        }
        else pos=1;
        x=abs(x);
        n=abs(n);
        //calculate x^n using binpow
        double a=x;
        while(n>0){
            if(n&1){
                ans*=a;
            }
            a=a*a;
            n/=2;
        }
        if(neg) ans*=-1;
        return (check?1/ans:ans);
    }
};