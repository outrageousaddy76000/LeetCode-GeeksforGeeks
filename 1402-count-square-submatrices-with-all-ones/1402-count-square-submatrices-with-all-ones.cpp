class Solution {
public:
    int countSquares(vector<vector<int>>& matrix){
        int ans=0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0) ans+=matrix[i][j];
                else if(matrix[i][j]){
                    matrix[i][j]+=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));
                    ans+=matrix[i][j];
                }
            }
        }
        return ans;
    }
};