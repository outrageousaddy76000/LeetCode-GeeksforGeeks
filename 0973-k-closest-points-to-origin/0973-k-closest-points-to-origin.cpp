typedef pair<int,int> pii;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pii,vector<pii>, greater<pii>> pq; // <distance, index>
        for(int i=0;i<points.size();i++){
            pq.push(make_pair(points[i][0]*points[i][0] + points[i][1]*points[i][1],i));
        }
        vector<vector<int>> ans;
        while(k--){
            pii top = pq.top();
            pq.pop();
            ans.push_back(points[top.second]);
        }
        return ans;
    }
};