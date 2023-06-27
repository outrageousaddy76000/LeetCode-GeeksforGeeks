class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map <long long int, int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans=0;
        int sum;
        for(auto &pr:m){
            if(m.find(pr.first+1)!=m.end()){
                sum=m[pr.first]+m[pr.first+1];
                ans=max(sum,ans);
            }
        }
        return ans;
    }
};