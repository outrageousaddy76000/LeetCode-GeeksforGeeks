class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int maxi = INT_MIN;
        unordered_map <int,pair<int,int>> ma;
        //element - firstindex,distance
        for(auto &pr:m){
            maxi = max(maxi,pr.second);
        }
        for(auto &pr:m){
            if(pr.second==maxi){
                ma[pr.first]={-1,0};
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(ma.find(nums[i])!=ma.end()){
                if(ma[nums[i]].first==-1){
                    ma[nums[i]].first=i;
                }
                ma[nums[i]].second=i-ma[nums[i]].first + 1;
            }
        }
        for(auto &pr:ma){
            ans=min(ans,pr.second.second);
        }
        return ans;
    }
};