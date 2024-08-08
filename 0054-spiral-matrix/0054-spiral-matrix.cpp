class Solution {
public:
    bool isvalid(int x,int y,int &n,int &m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> vis(n,vector <bool> (m,false));
        char curr='R';
        int x = 0,y=0;
        vector <int> ans;
        while(1){
            ans.push_back(matrix[x][y]);
            vis[x][y]=true;
            if(curr=='R'){
                if(isvalid(x,y+1,n,m) && !vis[x][y+1]) y++;
                else{
                    curr='D';
                    x++;
                    if(x>=n || vis[x][y]) break;
                }
            }
            else if(curr=='D'){
                if(isvalid(x+1,y,n,m) && !vis[x+1][y]) x++;
                else{
                    curr='L';
                    y--;
                    if(y<0 || vis[x][y]) break;
                }
            }
            else if(curr=='L'){
                if(isvalid(x,y-1,n,m) && !vis[x][y-1]) y--;
                else{
                    curr='U';
                    x--;
                    if(x<0 || vis[x][y]) break;
                }
            }
            else{
                if(isvalid(x-1,y,n,m) && !vis[x-1][y]) x--;
                else{
                    curr='R';
                    y++;
                    if(y>=m || vis[x][y]) break;
                }
            }
        }
        return ans;
    }
};