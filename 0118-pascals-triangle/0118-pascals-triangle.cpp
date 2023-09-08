class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> ans(numRows);
        for(int i=0;i<numRows;i++){
            //there will be nrows, for each row we create a vector
            //ans[i].size() = i+1;
            //1st row = 1; 2nd row = 2 and so on...
            //so we push back i+1 elements in ans[i]
            for(int j=0;j<i+1;j++){
                //for i+1 elements
                if(j==0 || j==i)
                    ans[i].push_back(1);
                else{
                    ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
        }
        return ans;
    }
};