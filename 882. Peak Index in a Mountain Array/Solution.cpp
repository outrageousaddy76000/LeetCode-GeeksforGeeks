class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {  
        //return the index of max element using binary search
        //arr[i+1]>arr[i] -- TTTTFFFF return the first false
        int n = arr.size();
        int low = 0,high=n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid+1]>arr[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};