class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long int sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%3!=0) return false;
        sum/=3;
        int ans=2;
        long long int sumeach=0;
        for(int i=0;i<n;i++){
            if(sumeach==sum && i){
                ans--;
                sumeach=0;
            }
            sumeach+=arr[i];
        }
        return ans<=0;
    }
};