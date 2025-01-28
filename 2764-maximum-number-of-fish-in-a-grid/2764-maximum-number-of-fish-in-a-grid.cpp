class Solution {
public:
    vector <vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    int n,m;
    int dfs(int x,int y,vector<vector<int>>& grid, vector<vector<bool>> &vis){
        int res=grid[x][y];
        vis[x][y]=true;
        for(auto &dir:directions){
            int x_ = x+dir[0];
            int y_ = y+dir[1];
            if(x_<0 || y_<0 || x_>=n || y_>=m) continue;
            if(!vis[x_][y_] && grid[x_][y_]>0){
                res+=dfs(x_,y_,grid,vis);
            }
        }
        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n,vector <bool> (m));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    ans=max(ans,dfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};