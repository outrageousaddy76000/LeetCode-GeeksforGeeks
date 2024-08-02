class Solution {
public:
    map <int,vector<char>> chars;
    map <int,vector<int>> indexes;
    void dfs(int i,vector <int> &vis,string &s,vector <vector <int>> &adj, int index){
        vis[i]=true;
        chars[index].push_back(s[i]);
        indexes[index].push_back(i);
        for(auto &val:adj[i]){
            if(!vis[val]) dfs(val,vis,s,adj,index);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //solution 2 - DFS
        chars.clear();
        indexes.clear();
        vector <vector <int>> adj(s.size());
        for(auto &pair:pairs){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        vector <int> vis(s.size());
        for(int i=0;i<s.size();i++){
            if(!vis[i]){
                dfs(i,vis,s,adj,i);
            }
        }
        for(auto &pr:chars) sort(pr.second.rbegin(),pr.second.rend());
        for(auto &pr:indexes) sort(pr.second.rbegin(),pr.second.rend());
        for(auto &pr:chars){
            vector <int> ind = indexes[pr.first];
            vector <char> ch = pr.second;
            while(ind.size()){
                s[ind[ind.size()-1]]=ch[ind.size()-1];
                ind.pop_back();
                ch.pop_back();
            }
        }
        return s;
    }
};