class Solution {
public:
    void dfs(int i,vector <int> &vis,string &s,vector <vector <int>> &adj,vector <int> &indexes, vector <char> &chars){
        vis[i]=true;
        chars.push_back(s[i]);
        indexes.push_back(i);
        for(auto &val:adj[i]){
            if(!vis[val]) dfs(val,vis,s,adj,indexes,chars);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //solution 2 - DFS
        vector <vector <int>> adj(s.size());
        for(auto &pair:pairs){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        vector <int> vis(s.size());
        for(int i=0;i<s.size();i++){
            if(!vis[i]){
                vector <int> indexes;
                vector <char> chars;
                dfs(i,vis,s,adj,indexes, chars);
                //dfs complete, operate here only
                sort(indexes.rbegin(),indexes.rend());
                sort(chars.rbegin(),chars.rend());
                while(indexes.size()){
                    s[indexes[indexes.size()-1]]=chars[indexes.size()-1];
                    chars.pop_back();
                    indexes.pop_back();
                }
            }
        }
        return s;
    }
};