class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& v) {
        //make adjacency list
        vector <vector <int>> adj(numCourses);
        vector <int> m(numCourses);
        for(int i=0;i<v.size();i++){
            adj[v[i][1]].push_back(v[i][0]);
            m[v[i][0]]++;
        }
        queue <int> q;
        vector <int> vis(numCourses);
        for(int i=0;i<numCourses;i++){
            if(m[i]==0) q.push(i);
        }
        while(!q.empty()){
            vis[q.front()]++;
            for(int i=0;i<adj[q.front()].size();i++){
                m[adj[q.front()][i]]--;
                if(m[adj[q.front()][i]]==0) q.push(adj[q.front()][i]);
            }
            q.pop();
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};