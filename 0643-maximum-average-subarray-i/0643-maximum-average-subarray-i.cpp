class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int i=0,j=k-1;
        double ans=INT_MIN;
        while(j<n){
            double sum;
            if(i==0) sum= pre[j];
            else sum=pre[j]-pre[i-1];
            ans=max(ans,sum);
            i++;
            j++;
        }
        return ans/k;
    }
};