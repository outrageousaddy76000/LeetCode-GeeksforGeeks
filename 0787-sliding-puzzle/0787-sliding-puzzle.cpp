class Solution {
private:
    unordered_map<string, int> memo;
    bool checkBoard(vector<vector<int>>&board){
        return board[0][0]==1 && board[0][1]==2 && board[0][2]==3 && board[1][0]==4 && board[1][1]==5 && board[1][2]==0;
    }
        string boardToString(vector<vector<int>>& board) {
        string state;
        for (auto& row : board) {
            for (auto& cell : row) {
                state += to_string(cell);
            }
        }
        return state;
    }
    int solve(vector<vector<int>>& board, int turns){
        if(turns>18) return INT_MAX;
        if(checkBoard(board)) return turns;
        string state = boardToString(board);
        if (memo.count(state) && memo[state] <= turns) return INT_MAX;
        memo[state] = turns;
        int r,c;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    r=i,c=j;
                    break;
                }
            }
        }
        int up=INT_MAX;
        int down=up,right=up,left=up;
        if (r != 0) {
            swap(board[r][c], board[r - 1][c]);
            up = solve(board, turns + 1);
            swap(board[r][c], board[r - 1][c]);
        }
        if (c != 0) {
            swap(board[r][c], board[r][c - 1]);
            left = solve(board, turns + 1);
            swap(board[r][c], board[r][c - 1]);
        }
        if (r != 1) {
            swap(board[r][c], board[r + 1][c]);
            down = solve(board, turns + 1);
            swap(board[r][c], board[r + 1][c]); 
        }
        if (c != 2) {
            swap(board[r][c], board[r][c + 1]);
            right = solve(board, turns + 1);
            swap(board[r][c], board[r][c + 1]);
        }
        return min(up,min(down,min(right,left)));
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        memo.clear();
        int ans = solve(board,0);
        return ans==INT_MAX?-1:ans;
    }
};