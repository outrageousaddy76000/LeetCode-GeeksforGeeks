class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n  = nums.size();
        vector <pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first=nums[i];
            v[i].second = i;
        }
        int ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            int j = i+1;
            while(j<n && v[j].first==v[i].first){
                if((v[j].second*v[i].second)%k==0) ans++;
                j++;
            }
        }
        return ans;
    }
};