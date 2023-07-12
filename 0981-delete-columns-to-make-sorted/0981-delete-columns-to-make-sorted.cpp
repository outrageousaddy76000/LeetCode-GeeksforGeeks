class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string> v(strs[0].size());
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                v[j]+=strs[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            string a = v[i];
            sort(a.begin(),a.end());
            if(v[i]!=a) ans++;
        }
        return ans;
    }
};