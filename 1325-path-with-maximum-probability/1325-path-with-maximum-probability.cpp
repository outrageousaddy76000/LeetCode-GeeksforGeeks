class Solution {
public:
    double max(double a,double b){
        if(a>b) return a;
        return b;
    }
    vector <bool> vis;
    vector <double> dis;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vis.resize(n,false);
        dis.resize(n,0);
        dis[start]=1.0;
        vis[start]=true;
        //create adjacency list
        priority_queue<pair<double,int>> pq;
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        int last = start;
        for(int cnt=0;cnt<n-1;cnt++){
            //apply dijkstra algo from start node
            for(auto &v: adj[last]){
                if(vis[v.first]==false){
                    dis[v.first]=max(dis[v.first],v.second*dis[last]);
                    pq.push({dis[v.first],v.first});
                }
            }
            //reduce time complexity here
            if(pq.empty()) break;
            pair <double,int> p;
            while(1){
                p = pq.top();
                pq.pop();
                if(vis[p.second]==false) break;
            }
            vis[p.second]=true;
            last=p.second;
            if(last==end) break;
        }
        return dis[end];
    }
};