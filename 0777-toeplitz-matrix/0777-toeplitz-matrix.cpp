class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m=matrix[0].size();
        //first row and first column pe iterate krke i++,j++ krke sare elements check krna h
        //1 2 3 4
        for(int j=0;j<m;j++){
            set <int> s;
            int i=0,k=j;
            while(i<n && k<m){
                s.insert(matrix[i++][k++]);
            }
            if(s.size()!=1) return false;
        }
        //5 9
        for(int i=1;i<n;i++){
            set <int> s;
            int k=i,j=0;
            while(k<n && j<m){
                s.insert(matrix[k++][j++]);
            }
            if(s.size()!=1) return false;
        }
        return true;
    }
};