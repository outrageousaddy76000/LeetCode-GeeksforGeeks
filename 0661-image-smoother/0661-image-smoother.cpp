class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector <vector<int>> ans(m,vector <int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int avg = 0;
                int cnt=0;
                for(int k = max(i-1,0);k<min(i+2,m);k++){
                    for(int l = max(j-1,0);l<min(j+2,n);l++){
                        cnt++;
                        avg+=img[k][l];
                    }
                }
                avg/=cnt;
                ans[i][j]=avg;
            }
        }
        return ans;
    }
};