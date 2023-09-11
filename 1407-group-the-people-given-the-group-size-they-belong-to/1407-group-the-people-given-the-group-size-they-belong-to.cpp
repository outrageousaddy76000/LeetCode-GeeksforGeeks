class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map <int,vector<int>> m;
        int n = groupSizes.size();
        for(int i=0;i<n;i++){
            m[groupSizes[i]].push_back(i);
        }
        vector <vector<int>> ans;
        for(auto &pr:m){
            int x = pr.second.size()/pr.first;
            //there will be x groups of size = pr.first
            int cnt=0;
            vector <int> v;
            for(auto &val:pr.second){
                v.push_back(val);
                cnt++;
                if(cnt==pr.first){
                    cnt=0;
                    ans.push_back(v);
                    v.clear();
                }
            }
        }
        return ans;
    }
};