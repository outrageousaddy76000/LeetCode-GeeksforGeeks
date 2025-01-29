class DSU{
public:
    vector <int> parent;
    vector <int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(),parent.end(),0);
    }

    int findParent(int a){
        if(parent[a]==a) return a;
        return parent[a]=findParent(parent[a]);
    }

    bool unionSets(int a,int b){
        int x = findParent(a);
        int y = findParent(b);
        if(x!=y){
            if(rank[x]<rank[y]){
                parent[x]=y;
            }
            else if(rank[y]<rank[x]){
                parent[y]=x;
            }
            else{
                parent[y]=x;
                rank[x]++;
            }
            return true;
        }
        return false;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(auto &val:edges){
            if(!dsu.unionSets(val[0]-1,val[1]-1)) return {val[0],val[1]};
        }
        return {-1};
    }
};