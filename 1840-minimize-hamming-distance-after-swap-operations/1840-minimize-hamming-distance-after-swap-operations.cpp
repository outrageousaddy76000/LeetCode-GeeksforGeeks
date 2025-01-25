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
    void printParents(){
        for(auto &val:parent) cout<<val<<" ";
        cout<<endl;
    }
    void printRanks(){
        for(auto &val:rank) cout<<val<<" ";
        cout<<endl;
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
        unordered_map <int,unordered_multiset<int>> mp1,mp2;
        for(int i=0;i<n;i++){
            int index=dsu.findParent(i);
            mp1[index].insert(source[i]);
            mp2[index].insert(target[i]);
        }
        for(auto &[index, s1]:mp1){
            unordered_multiset <int> s2 = mp2[index];
            //now deal with these 2 multisets
            for(auto &val:s1){
                auto it = s2.find(val);
                if(it==s2.end()) ans++;
                else s2.erase(it);
            }
        }
        return ans;
    }
};