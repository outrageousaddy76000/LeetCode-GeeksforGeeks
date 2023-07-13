class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int r,c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='R'){
                    r=i,c=j;
                    break;
                }
            }
        }
        //check in rth row and cth column
        int ans=0;
        //left of rook
        for(int i=c-1;i>=0;i--){
            if(board[r][i]=='.') continue;
            else if (board[r][i]>=65 && board[r][i]<=90){
                break;
            }
            else{
                ans++;
                break;
            }
        }
        //right of rook
        for(int i=c+1;i<m;i++){
            if(board[r][i]=='.') continue;
            else if (board[r][i]>=65 && board[r][i]<=90){
                break;
            }
            else{
                ans++;
                break;
            }
        }
        //upwards of rook
        for(int i=r-1;i>=0;i--){
            if(board[i][c]=='.') continue;
            else if (board[i][c]>=65 && board[i][c]<=90){
                break;
            }
            else{
                ans++;
                break;
            }
        }
        //downwards of rook
        for(int i=r+1;i<n;i++){
            if(board[i][c]=='.') continue;
            else if (board[i][c]>=65 && board[i][c]<=90){
                break;
            }
            else{
                ans++;
                break;
            }
        }
        return ans;
    }
};