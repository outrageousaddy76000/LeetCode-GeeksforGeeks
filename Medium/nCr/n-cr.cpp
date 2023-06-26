//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const long long int mod =1e9+7;
    long long binpow(long long r, long long b) {
        long long int a=1;
        for(int i=1;i<=r;i++){
            a*=i;
            a%=mod;
        }
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
    int nCr(int n, int r){
        if(r>n) return 0;
        long long int ans=1;
        for(int i=n-r+1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        long long int inv = binpow(r,mod-2);
        return (ans%mod * inv%mod)%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends