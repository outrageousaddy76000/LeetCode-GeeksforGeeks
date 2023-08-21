//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
vector<pair<int, int>> move = {
    {1, 0},   // Down
    {-1, 0},  // Up
    {0, 1},   // Right
    {0, -1},  // Left
    {1, 1},   // Bottom-right
    {1, -1},  // Bottom-left
    {-1, 1},  // Top-right
    {-1, -1}  // Top-left
    // You can add more movements here if needed
};
int n,m;
bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m){
        return false;
    }
    return true;
}
    int Count(vector<vector<int> >& matrix) {
        int ans=0;
        n = matrix.size();
        m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) continue;
                int cnt=0;
                for(auto &val:move){
                    if(isValid(i+val.first,j+val.second)){
                        matrix[i+val.first][j+val.second]==0?cnt++:cnt;
                    }
                }
                if(cnt%2==0 && cnt) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends