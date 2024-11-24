class Solution {
private:
    long long int min(long long int a, long long int b){
        if(a<b) return a;
        return b;
    }
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt=0;
        long long int sum=0;
        long long int mini=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) cnt++;
                mini = min(mini,abs(matrix[i][j]));
            }
        }
        if(cnt&1){
            return sum-2*mini;
        }
        else return sum;
    }
};