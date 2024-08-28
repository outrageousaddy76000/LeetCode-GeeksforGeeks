class Solution {
public:
    int n,m;
    vector <pair<int,int>> move = {{1,0},{-1,0},{0,-1},{0,1}};
    bool isvalid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    bool dfs(int i,int j,vector<vector<int>>& grid2, vector<vector<bool>>& vis,vector <vector<int>> &grid1){         
        vis[i][j]=1;
        bool ans;
        if(grid1[i][j]==1) ans=true;
        else ans=false;
        for(auto &p:move){
            int dx = p.first;
            int dy = p.second;
            int newx = i+p.first;
            int newy = j+p.second;
            if(isvalid(newx,newy)){
                if(grid2[newx][newy]==1 && !vis[newx][newy]){
                    ans&=dfs(newx,newy,grid2,vis,grid1);
                }
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();
        vector <vector <bool>> vis(n,vector <bool> (m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(grid2[i][j]==0) vis[i][j]=1;
                    else {
                        if(dfs(i,j,grid2,vis,grid1)) ans++;
                    }
                }
            }
        }
        return ans;
    }
};