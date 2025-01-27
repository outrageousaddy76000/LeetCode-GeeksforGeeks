class Solution {
public:
    bool dfs(int node, int val, vector <bool> &vis, vector <vector<int>> &adj){
        if(node==val) return true;
        vis[node]=true;
        bool ans=false;
        for(auto &v:adj[node]){
            if(!vis[v]) ans=(ans|dfs(v,val,vis,adj));
        }
        return ans;
    }
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector <vector<int>> adj(num);
        for(auto &val:p){
            adj[val[0]].push_back(val[1]);
        }
        vector <bool> ans(q.size());
        for(int i=0;i<q.size();i++){
            vector<bool> vis(num, false);
            ans[i]=dfs(q[i][0],q[i][1], vis, adj);
        }
        return ans;
    }
};