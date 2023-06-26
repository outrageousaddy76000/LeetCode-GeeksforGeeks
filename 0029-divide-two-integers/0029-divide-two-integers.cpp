class Solution {
public:
    int divide(int dividend, int divisor) {
        if(1LL*((1LL*dividend)/(1LL*divisor))>INT_MAX) return INT_MAX;
        else if(1LL*((1LL*dividend)/(1LL*divisor))<INT_MIN) return INT_MIN;
        return dividend/divisor;
    }
};