class Solution {
public:
    int countSquares(vector<vector<int>>& matrix){
        int ans=0;
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]){
                    matrix[i][j]+=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));
                    ans+=matrix[i][j];
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            ans+=matrix[i][0];
        }
        for(int i=1;i<matrix[0].size();i++){
            ans+=matrix[0][i];
        }
        return ans;
    }
};