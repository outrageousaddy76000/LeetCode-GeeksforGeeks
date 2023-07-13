class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        //greater than eqaul 1 -- add the top and bottom area
        //add height of corner elements to surface area
        //for each row and each column as we move along we add the area diff
        int n = grid.size();
        if(n==1){
            return 2 + 4*grid[0][0];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>=1){
                    ans+=2;
                }
                if((i==0 && (j==0 || j==n-1)) || (i==n-1 && (j==0 || j==n-1))){
                    ans+=2*grid[i][j];
                }
                else if(i==0 || j==0 || i==n-1 || j==n-1){
                    ans+=grid[i][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                ans+=abs(grid[i][j]-grid[i][j+1]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                ans+=abs(grid[j][i]-grid[j+1][i]);
            }
        }
        return ans;
    }
};