class Solution {
private:
    vector <vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(int i, int j, string &word, int str_index,vector<vector<bool>>& vis,vector<vector<char>>& board){
        // cout<<i<<" "<<j<<endl;
        if(str_index==word.size()) return true;
        bool ans=false;
        vis[i][j]=true;
        for(auto &d:dir){
            int i_ = i+d[0];
            int j_ = j+d[1];
            if(i_>=board.size() || i_<0 || j_>=board[0].size() || j_<0 || vis[i_][j_] || board[i_][j_]!=word[str_index]) continue;
            ans= ans|dfs(i_,j_,word,str_index+1,vis,board);
        }
        vis[i][j]=false;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool ans=false;
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    ans=ans | dfs(i,j,word,1,vis,board);
                }
            }
        }
        return ans;
    }
};