class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //take nums[j], largest value to its left, largest value to its right
        int n = nums.size();
        vector <int> pre(n);
        vector <int> post(n);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            post[i]=max(post[i+1],nums[i]);
        }
        long long int ans=INT_MIN;
        for(int i=1;i<n-1;i++){
            ans=max(ans,(1LL*pre[i-1]-nums[i])*1LL*post[i+1]);
        }
        return max(ans,1LL*0);
    }
};