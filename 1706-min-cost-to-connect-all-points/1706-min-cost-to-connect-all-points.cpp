class DSU{
public:
    vector <int> parent, rank;
    DSU(int size){
        parent.resize(size);
        rank.resize(size);
        iota(parent.begin(),parent.end(),0);
    }

    int findParent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x]);
    }

    void unionByRank(int a, int b){
        int parent1 = findParent(a);
        int parent2 = findParent(b);
        if(rank[parent1]>rank[parent2]){
            parent[parent2]=parent1;
        }
        else if(rank[parent2]>rank[parent1]){
            parent[parent1]=parent2;
        }
        else{
            parent[parent1]=parent2;
            rank[parent2]++;
        }
    }
};

class Solution {
private:
    int findByKruskals(vector <vector<int>> cost){
        int n = cost.size();
        int ans=0;
        DSU dsu(n);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push(make_pair(cost[i][j],make_pair(i,j)));
            }
        }
        int cnt=0;
        while(cnt<n-1){
            pair<int,pair<int,int>> top = pq.top();
            pq.pop();
            int first = top.second.first;
            int second = top.second.second;
            if(dsu.findParent(first)!= dsu.findParent(second)){
                dsu.unionByRank(first,second);
                cnt++;
                ans+=top.first;
            }
        }
        return ans;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector <vector<int>> cost(points.size(),vector <int> (points.size(),INT_MAX));
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                cost[i][j]=abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
            }
        }
        return findByKruskals(cost);
        // return findByPrims(cost);
    }
};