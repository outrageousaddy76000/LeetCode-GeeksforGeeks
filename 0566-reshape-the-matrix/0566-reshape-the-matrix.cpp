class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r,vector<int> (c));
        int n = mat.size();
        int m = mat[0].size();
        if((r*c)!=(m*n)) return mat;
        int k=0,l=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //keep to to ans vector
                ans[k][l]=mat[i][j];
                if(l==c-1){
                    k++;
                    l=0;
                }
                else l++;
            }
        }
        return ans;
    }
};