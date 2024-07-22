class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector <string> ans;
        map <int,string> m;
        for(int i=0;i<heights.size();i++){
            m[heights[i]]=names[i];
        }
        for(auto &pr:m){
            ans.push_back(pr.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};