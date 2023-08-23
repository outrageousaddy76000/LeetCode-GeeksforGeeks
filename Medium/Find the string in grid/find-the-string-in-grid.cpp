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
    };
    
    int n, m;
    
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    bool check(int i,int j, vector<vector <char>> &grid, string word,int index,int a,int b){
        if(index == word.size()) return true;
        if(!isValid(i,j)) return false;
        if(grid[i][j]!=word[index]) return false;
        return check(i+a,j+b,grid,word,index+1,a,b);
        
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    n = grid.size();
	    m=grid[0].size();
	    vector <vector<int>> ans;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            bool correct =false;
	            for(auto &val:move){
                    if(check(i,j,grid,word,0,val.first,val.second)){
                        correct =true;
                        break;
                    } 
	            }
	            if(correct){
                    vector<int> v = {i, j};
                    ans.push_back(v);
	            }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends