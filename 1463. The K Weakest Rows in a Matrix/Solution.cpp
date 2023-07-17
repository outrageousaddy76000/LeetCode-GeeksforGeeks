class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<mat.size();i++){
            pq.push({count(mat[i].begin(),mat[i].end(),1),i});
        }
        vector <int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};