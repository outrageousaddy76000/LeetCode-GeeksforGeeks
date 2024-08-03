class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        //count the number of zeroes from right to left
        int n = grid.size();
        vector <int> v;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0) cnt++;
                else break;
            }
            v.push_back(cnt);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            //earliest row to fill the ith row
            for(int j=i;j<=n;j++){
                if(j==n) return -1;
                if(v[j]>=n-i-1){
                    //can satisfy the ith row, so bring the jth row to the ith row
                    int nswaps = j-i;
                    int index=j;
                    while(nswaps--){
                        swap(v[index],v[index-1]);
                        index--;
                        ans++;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};