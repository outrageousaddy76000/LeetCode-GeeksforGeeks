class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        vector <int> pre(arr.size());
        pre[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            pre[i]=pre[i-1]+arr[i];
        }
        for(int i=0;i<arr.size();i++){
            for(int j=i;j<arr.size();j+=2){
                if(i==j) ans+=arr[i];
                else{
                    if(i){
                        ans+=pre[j]-pre[i-1];
                    }
                    else{
                        ans+=pre[j];
                    }
                }
            }
        }
        return ans;
    }
};