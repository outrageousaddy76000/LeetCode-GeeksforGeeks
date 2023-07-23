class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i=0,j=0,ans=0;
        while(i<n){
            ans+=matrix[i++][j++];
        }
        i=n-1,j=0;
        while(i>=0){
            ans+=matrix[i--][j++];
        }
        if(n%2!=0) ans-= matrix[n/2][n/2];
        return ans;
    }
};