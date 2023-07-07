//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //0 means + + - or - - + or + - 0
        sort(arr,arr+n);
        unordered_map <int,int> m; 
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        if(m.find(0)!=m.end()){
            if(m[0]>=3) return 1;
            for(int i=0;arr[i]!=0;i++){
                if(m.find(-1*arr[i])!=m.end()) return 1;
            }
        }
        //if -(sum of 2 neg numbers == any pos number)
        for(int i=0;arr[i]<0;i++){
            for(int j=i+1;arr[j]<0;j++){
                if(m.find(-1*(arr[i]+arr[j]))!=m.end()) return 1;
            }
        }
        for(int i=n-1;arr[i]>0;i--){
            for(int j=i-1;arr[j]>0;j--){
                if(m.find(-1*(arr[i]+arr[j]))!=m.end()) return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends