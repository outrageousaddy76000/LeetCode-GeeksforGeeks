class Solution {
private:
    vector <vector<int>> dir = {
        {-1,0},{1,0},{0,1},{0,-1}
    };
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();
        vector <pair<int,int>> q(k);
        for(int i=0;i<k;i++){
            q[i]={queries[i],i};
        }
        sort(q.begin(),q.end());
        vector <int> ans(k);
        priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater <>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        vis[0][0]=true;
        int cnt=0;
        for(auto [val,index]:q){
            while(!pq.empty() && pq.top().first<val){
                //can move forward from the current cell
                auto [x,i] = pq.top();
                pq.pop();
                int row = i.first;
                int col = i.second;
                cnt++;
                for(auto &d:dir){
                    if(row+d[0]>=m || row+d[0]<0) continue;
                    if(col+d[1]>=n || col+d[1]<0) continue;
                    if(vis[row+d[0]][col+d[1]]) continue;
                    pq.push((make_pair(grid[row+d[0]][col+d[1]],make_pair(row+d[0],col+d[1]))));
                    vis[row+d[0]][col+d[1]]=true;
                }
            }
            ans[index]=cnt;
        }
        return ans;
    }
};