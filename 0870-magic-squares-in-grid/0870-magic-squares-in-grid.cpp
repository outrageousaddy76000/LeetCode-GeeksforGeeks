class Solution {
public:
    bool checkdiagonals(int x,int y,vector <vector <int>> &grid){
        if(grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2]==15) return true;
        return false;
    }
    bool checkfull(int x,int y,vector <vector <int>> &grid){
        set <int> s;
        s.insert(grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2]); //main diag
        s.insert(grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y]); //other diag
        for (int i = x; i < x + 3; ++i) {
            int rowSum = grid[i][y] + grid[i][y + 1] + grid[i][y + 2];
            s.insert(rowSum);
        }
        for (int j = y; j < y + 3; ++j) {
            int colSum = grid[x][j] + grid[x + 1][j] + grid[x + 2][j];
            s.insert(colSum);
        }
        set <int> nums;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                nums.insert(grid[i][j]);
            }
        }
        return s.size()==1 && nums.size()==9 && *nums.begin()==1 && *nums.rbegin()==9;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                //check diagonals starting from i,j if true then do the whole process
                if(checkdiagonals(i,j,grid)){
                    //check the 3*3 starting from i,j
                    if(checkfull(i,j,grid)) ans++;
                }
            }
        }
        return ans;
    }
};