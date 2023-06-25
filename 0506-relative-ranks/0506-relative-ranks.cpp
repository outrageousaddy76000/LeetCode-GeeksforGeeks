class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector <pair<int,int>> v(score.size());
        for(int i=0;i<score.size();i++){
            v[i].first=score[i];
            v[i].second = i;
        }
        sort(v.rbegin(),v.rend());
        vector <string> ans(score.size());
        int i=1;
        for(auto &val:v){
            if(i==1){
                ans[val.second]="Gold Medal";
            }
            else if(i==2){
                ans[val.second]="Silver Medal";
            }
            else if (i==3){
                ans[val.second]="Bronze Medal";
            }
            else ans[val.second]=to_string(i);
            i++;
        }
        return ans;
    }
};