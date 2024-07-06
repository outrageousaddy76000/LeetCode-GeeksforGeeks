class Solution {
public:
    int passThePillow(int n, int time) {
        time%=(n-1)*2;
        if(time<=n-1){
            return time+1;
        }
        return n-(time-(n-1));
    }
};