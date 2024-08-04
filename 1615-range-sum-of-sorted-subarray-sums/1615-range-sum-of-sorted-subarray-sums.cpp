class Solution {
public:
    const int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector <int> sums;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(),sums.end());
        long long int ans=0;
        left--;
        right--;
        for(int i=left;i<=right;i++){
            ans+=sums[i];
            ans%=mod;
        }
        return ans;
    }
};