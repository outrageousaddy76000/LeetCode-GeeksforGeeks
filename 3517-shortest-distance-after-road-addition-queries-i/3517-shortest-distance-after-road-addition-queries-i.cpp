class Solution {
public:
    int bfs(vector<vector<int>>& adj) {
        vector<int> level(adj.size(), -1);
        queue<int> q;
        q.push(0);
        level[0] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (level[neighbor] == -1) {
                    level[neighbor] = level[node] + 1;
                    q.push(neighbor);
                    if (neighbor == adj.size()-1) {
                        return level[neighbor];
                    }
                }
            }
        }
        
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector <int> ans;
        vector <vector <int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(int i=0;i<queries.size();i++){
            //apply bfs
            adj[queries[i][0]].push_back(queries[i][1]);
            //apply bfs starting from 0
            int current = bfs(adj);
            ans.push_back(current);
        }
        return ans;
    }
};