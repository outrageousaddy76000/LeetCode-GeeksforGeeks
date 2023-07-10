class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector <int> primes(33);
        primes[1]=0;
        primes[2]=1;
        primes[3]=1;
        primes[5]=1;
        primes[7]=1;
        primes[11]=1;
        primes[13]=1;
        primes[17]=1;
        primes[19]=1;
        primes[23]=1;
        primes[29]=1;
        primes[31]=1;
        int ans=0;
        for(int i=left;i<=right;i++){
            int x = __builtin_popcount(i);
            if(primes[x]) ans++;
        }
        return ans;
    }
};