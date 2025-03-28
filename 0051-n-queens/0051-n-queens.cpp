class Solution {
private:
    vector<vector<string>> ans;
    void place(int n, vector <int> &current){
        vector<string> valid;
            for(int i=0;i<n;i++){
                //Q is at index current[i]
                string ansRow="";
                for(int j=0;j<n;j++){
                    if(current[i]==j) ansRow+="Q";
                    else ansRow+=".";
                }
                valid.push_back(ansRow);
            }
        ans.push_back(valid);
    } 
    bool blocks(int n, vector <int> &current, int row, int col){
        //the queens are already placed at i,current[i], 
        for(int i=0;i<n;i++){
            if(current[i]==-1) break;
            //check column collision
            if(current[i]==col) return true;
            //check diagonal collision
            if((abs(i-row)==abs(current[i]-col))) return true;
        }
        return false;
    }
    void solve(int n, int index, vector<int> current){
        if(index==n){
            //place the queens, the queens are at i,current[i]
            place(n, current);
            return;
        }
        for(int i=0;i<n;i++){
            //try to place the queen in the index row, col = i
            if(!blocks(n, current,index,i)){
                current[index]=i;
                // cout<<index<<" "<<i<<endl;
                solve(n,index+1, current);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector <int> current(n,-1);
        solve(n,0,current);
        return ans;
    }
};