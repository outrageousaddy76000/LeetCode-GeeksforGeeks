//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        vector <long long int> pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        int ans=0;
        //same prefix sum means inbetween sum==0
        //prefix sum means 0 to i sum==0
        //calculate diff between same prefix sums
        //calculate index for 0 prefix sums
        unordered_map <int,int> m;
        for(int i=0;i<n;i++){
            if(pre[i]==0){
                ans=max(ans,i+1);
            }
            else if(m.find(pre[i])!=m.end()){
                ans=max(i-m[pre[i]],ans);
            }
            else m[pre[i]]=i;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends