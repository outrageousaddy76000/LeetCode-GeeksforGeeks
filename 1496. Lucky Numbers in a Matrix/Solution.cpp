class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <int> r(n);
        vector <int> c(m);
        for(int i=0;i<n;i++){
            r[i]=*min_element(matrix[i].begin(),matrix[i].end());
        }
        for(int i=0;i<m;i++){
            int maxi = INT_MIN;
            for(int j=0;j<n;j++){
                maxi=max(maxi,matrix[j][i]);
            }
            c[i]=maxi;
        }
        for(auto &val:r) cout<<val<<" ";
        cout<<endl;
        for(auto &val:c) cout<<val<<" ";
        vector <int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==c[j] && matrix[i][j]==r[i]) ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};