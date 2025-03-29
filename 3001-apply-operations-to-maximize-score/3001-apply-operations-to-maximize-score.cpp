class Solution {
private:
    const int mod = 1000000007;
    long long modBinPow(long long a, long long b){
        a %= mod;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    vector <int> getPrimes(int &n){
        //returns all primes upto n
        vector <int> primes;
        vector <bool> sieve(n+1,true);
        sieve[0]=false;
        sieve[1]=false;
        for(int i=2;i<=n;i++){
            //adjusted primes with sieve loop
            if(sieve[i]){
                //unmarked
                primes.push_back(i);
                if(1LL*i*i<=n)
                for(int j=i*i;j<=n;j+=i){
                    sieve[j]=false;
                }
            }
        }
        return primes;
    }

    vector<int> getScores(vector<int> &primes, vector<int> &nums) {
        vector<int> scores(nums.size());
        
        for(int i=0;i<nums.size();i++) {
            int val = nums[i];
            int cnt = 0;
            for (auto &x:primes){
                if(x*x>val) break;
                if(val%x==0){
                    cnt++;
                    while(val%x==0) val/=x;
                }
            }
            if(val>1) cnt++;
            scores[i] = cnt;
        }
        return scores;
    }


    vector <pair<int,int>> getSorted(vector <int> &nums){
        vector <pair<int,int>> sorted;
        for(int i=0;i<nums.size();i++){
            sorted.push_back({nums[i],i});
        }
        sort(sorted.rbegin(),sorted.rend());
        return sorted;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> primes = getPrimes(*max_element(nums.begin(),nums.end()));
        vector <int> score = getScores(primes,nums);
        vector <pair<int,int>> sorted = getSorted(nums);
        //calculated pre index, post index and then calculate ans
        long long int ans=1;
        stack <int> st;
        vector <int> prev(n,-1),next(n,nums.size());
        for(int i=0;i<n;i++){
            while(!st.empty() && score[st.top()]<score[i]){
                //pop and set next
                next[st.top()]=i;
                st.pop();
            }
            //update prev and push
            if(!st.empty()) prev[i]=st.top();
            st.push(i);
        }
        //now calculate ans
        for(auto [val, i]:sorted){
            long long int maxi = 1LL*(i-prev[i])*(next[i]-i);
            ans*=modBinPow(1LL*val,1LL*min(1LL*k,maxi));
            ans%=mod;
            k-=maxi;
            if(k<=0) break;
        }
        return ans;
    }
};