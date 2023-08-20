//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    //find first index and last index using binary search
	    int low = 0,high=n-1;
	    while(high>=low){
	        int mid = low +(high-low)/2;
	        if(arr[mid]>=x){
	            high=mid-1;
	        }
	        else if(arr[mid]<x){
	            low = mid+1;
	        }
	    }
	    int first = low;
	    low = first;
	    high = n-1;
	    while(high>=low){
	        int mid = low +(high-low)/2;
	        if(arr[mid]>x){
	            high=mid-1;
	        }
	        else if(arr[mid]<=x){
	            low = mid+1;
	        }
	    }
	    int last = low;
	    return last-first;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends