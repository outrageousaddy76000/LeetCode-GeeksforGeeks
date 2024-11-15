class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        int start=0,end;
        int ans=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                ans=n-i;
                break;
            }
        }
        cout<<ans;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                end=i+1;
                ans=min(ans,end);
                break;
            }
            if(i==0){
                return 0;
            }
        }
        while(start<n && end<n){
            if(start && arr[start]<arr[start-1]){
                break;
            }
            while(end<n && arr[end]<arr[start]) end++;
            ans=min(ans,end-start-1);
            start++;
        }
        return ans;
    }
};