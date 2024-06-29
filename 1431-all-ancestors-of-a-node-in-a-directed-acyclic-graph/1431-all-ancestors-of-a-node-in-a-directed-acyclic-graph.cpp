class Solution {
public:
    static vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);

        for (auto& e: edges) {//Build adjacent list
            int v=e[0], w=e[1];
            adj[v].push_back(w);
            deg[w]++;// indegree
        }
        queue<int> q;
        for(int i=0; i<n; i++)
            if (deg[i]==0) q.push(i);

        vector<set<int>> ancestor(n);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for (int w : adj[v]) {
                // Add v and all ancestors of v to the ancestors of w
                ancestor[w].insert(v);
                ancestor[w].insert(ancestor[v].begin(), ancestor[v].end());

                if (--deg[w] == 0) q.push(w);  //push vertex with 0 deg
            }
        }
        vector<vector<int>> ans(n);
        for(int i=0; i<n; i++)
            ans[i]=vector<int>(ancestor[i].begin(), ancestor[i].end());
        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();