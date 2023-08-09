//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    vector <int> v;
    void getprimes(int n){
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                v.push_back(i);
                n/=i;
            }
        }
        if(n>2){
            v.push_back(n);
        }
    }
    long long int largestPrimeFactor(int n){
        //sieve of erastrothenes
        getprimes(n);
        return v[v.size()-1];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends