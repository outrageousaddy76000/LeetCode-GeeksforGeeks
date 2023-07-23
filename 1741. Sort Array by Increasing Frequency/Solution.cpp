class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map <int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector <pair<int,int>> v;
        for(auto &pr:m){
            v.push_back(make_pair(pr.second,pr.first));
        }
        sort(v.begin(),v.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        });
        vector <int> ans;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].first;j++){
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};