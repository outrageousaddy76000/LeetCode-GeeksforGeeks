class Solution {
public:
    void helper(int index, vector<vector<int>>& adj, vector <bool> &vis){
        vis[index]=true;
        for(auto &val:adj[index]){
            if(!vis[val]){
                helper(val,adj,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int ans=0;
        vector<vector<int>> adj(stones.size());
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[j][1]==stones[i][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //n - total components is the answer
        vector <bool> vis(stones.size(),false);
        for(int i=0;i<stones.size();i++){
            if(!vis[i]){
                ans++;
                helper(i,adj,vis);
            }
        }
        return stones.size()-ans;
    }
};