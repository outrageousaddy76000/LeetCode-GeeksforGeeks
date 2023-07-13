class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //build adjacency list
        unordered_map <int,int> m;
        vector <vector<int>> adj(n+1);
        for(int i=0;i<trust.size();i++){
            adj[trust[i][1]].push_back(trust[i][0]);
            m[trust[i][0]]++;
        }
        for(int i=1;i<adj.size();i++){
            if(adj[i].size()>=n-1){
                if(m.find(i)==m.end()) return i;
                return -1;
            }
        }
        return -1;
    }
};