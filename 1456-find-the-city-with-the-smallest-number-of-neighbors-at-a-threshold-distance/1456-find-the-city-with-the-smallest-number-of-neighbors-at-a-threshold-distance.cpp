class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //dijkstra from each city
        int ans=0;
        int anscount=INT_MAX;
        //create adjacency list
        vector <vector <pair<int,int>>> adj(n);
        for(auto &val:edges){
            adj[val[0]].push_back({val[1],val[2]});
            adj[val[1]].push_back({val[0],val[2]});
        }
        for(int start=0;start<n;start++){
            vector<int> dist(n, INT_MAX);
            vector<bool> vis(n, false);
            dist[start] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, start});
            
            while (!pq.empty()) {
                int current = pq.top().second;
                pq.pop();
                
                if (vis[current]) continue;
                vis[current] = true;
                
                for (auto &val : adj[current]) {
                    int neighbor = val.first;
                    int weight = val.second;
                    
                    if (!vis[neighbor] && dist[current] + weight < dist[neighbor]) {
                        dist[neighbor] = dist[current] + weight;
                        pq.push({dist[neighbor], neighbor});
                    }
                }
            }
            int cnt=0;
            for(auto &val:dist){
                if(val<=distanceThreshold) cnt++;
            }
            if(cnt<=anscount){
                ans=start;
                anscount=cnt;
            }
        }
        return ans;
    }
};