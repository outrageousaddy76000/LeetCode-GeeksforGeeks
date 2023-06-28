//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool check(int n){
        unordered_map <int,int> m;
        while(1){
            //extract digits
            vector <int> v;
            int x = n;
            while(x>0){
                v.push_back(x%10);
                x/=10;
            }
            //square and add
            long long int a=0;
            for(int i=0;i<v.size();i++){
                a+=pow(v[i],2);
            }
            if(a==1){
                return true;
            }
            if(m[a]>0){
                return false;
            }
            m[a]++;
            n=a;
        }
    }
    int nextHappy(int N){
        for(int i=N+1;i<10e4+2;i++){
            if(check(i)) return i;
        }
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends