class Solution {
public:    
    int n,m;
    void dfs(vector <vector <int>> &grid, int x, int y){
        grid[x][y]=0;
        if(x+1<n && grid[x+1][y]==1){
            dfs(grid,x+1,y);
        }
        if(x-1>=0 && grid[x-1][y]==1){
            dfs(grid,x-1,y);
        }
        if(y+1<m && grid[x][y+1]==1){
            dfs(grid,x,y+1);
        }
        if(y-1>=0 && grid[x][y-1]==1){
            dfs(grid,x,y-1);
        }
    }
    int findislands(vector <vector <int>> &grid){
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    islands++;
                    if(islands>1) break;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        //step 1 - if already more than 1 islands, return 0;
        //step 2 - else try making every 1 - > 0 one by one and find the number of islands, if 2 break;
        //step 3 - else return 2;
        n = grid.size();
        m = grid[0].size();
        vector <vector<int>> matrix = grid;
        if(findislands(matrix)>1) return 0;
        //change ones to 0s and find islands
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                    matrix = grid;
                    matrix[i][j]=0;
                    if(findislands(matrix)>1) return 1;
                }
            }
        }
        if(cnt==0){
            //no 1s present 
            return 0;
        }
        else if(cnt==1){
            return 1;
        }
        return 2;
    }
};