#include <vector>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int findParent(int a) {
        if (parent[a] == a) 
            return a;
        return parent[a] = findParent(parent[a]);
    }

    void unionSets(int a, int b) {
        int rootA = findParent(a);
        int rootB = findParent(b);

        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
};


class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        for(auto &v:allowedSwaps){
            dsu.unionSets(v[0],v[1]);
        }
        int ans=0;
        unordered_map <int,unordered_multiset<int>> mp;
        for(int i=0;i<n;i++){
            int index=dsu.findParent(i);
            mp[index].insert(source[i]);
        }
        for(int i=0;i<n;i++){
            int index=dsu.findParent(i);
            auto it = mp[index].find(target[i]);
            if(it!=mp[index].end()) mp[index].erase(it);
            else ans++;
        }
        return ans;
    }
};