//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        long long int currsum=0;
        long long int maxsum=0;
        //update currsum with next index if currsum<0
        for(int i=0;i<n;i++){
            if(currsum<0) currsum=arr[i];
            else {
                currsum+=arr[i];
            }
            maxsum=max(currsum,maxsum);
        }
        if(!maxsum) maxsum=*max_element(arr,arr+n);
        return maxsum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends