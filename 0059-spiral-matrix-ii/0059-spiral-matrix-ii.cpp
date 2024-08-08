class Solution {
public:
    bool isvalid(int x,int y,int &n){
        return x>=0 && y>=0 && x<n && y<n;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<bool>> vis(n,vector <bool> (n,false));
        char curr='R';
        int elem=1;
        int x = 0,y=0;
        vector <vector <int>> ans(n,vector <int> (n));
        while(1){
            ans[x][y]=elem;
            elem++;
            vis[x][y]=true;
            if(curr=='R'){
                if(isvalid(x,y+1,n) && !vis[x][y+1]) y++;
                else{
                    curr='D';
                    x++;
                    if(x>=n || vis[x][y]) break;
                }
            }
            else if(curr=='D'){
                if(isvalid(x+1,y,n) && !vis[x+1][y]) x++;
                else{
                    curr='L';
                    y--;
                    if(y<0 || vis[x][y]) break;
                }
            }
            else if(curr=='L'){
                if(isvalid(x,y-1,n) && !vis[x][y-1]) y--;
                else{
                    curr='U';
                    x--;
                    if(x<0 || vis[x][y]) break;
                }
            }
            else{
                if(isvalid(x-1,y,n) && !vis[x-1][y]) x--;
                else{
                    curr='R';
                    y++;
                    if(y>=n || vis[x][y]) break;
                }
            }
        }
        return ans;
    }
};