class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector <int> primes(1e6+1);
        iota(primes.begin(),primes.end(),0);
        primes[1]=0;
        for(int i=2;i*i<=primes.size()-1;i++){
            if(primes[i]!=0)
                for (int j = i * i; j <= primes.size()-1; j += i)
                    primes[j] = 0;
        }
        int ans=0;
        for(int i=left;i<=right;i++){
            int x = __builtin_popcount(i);
            if(primes[x]) ans++;
        }
        return ans;
    }
};