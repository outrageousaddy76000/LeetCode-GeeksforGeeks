//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
 {int n1=0;
    int mz=0;
    int mo=0;
        for(int i=0;i<n;i++){
            if(a[i]==1)n1++;
        }
        
        int cz=0,co=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if((cz-co)<1){
                cz=0;
                co=0;
            }
            if(a[i]==0){
                cz++;
            }
            else{
                co++;
            }
            maxi=max(maxi,cz-co);
            if(maxi==cz-co){
                mz=cz;
                mo=co;
            }
        }
        return n1-mo+mz;
     
 }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends