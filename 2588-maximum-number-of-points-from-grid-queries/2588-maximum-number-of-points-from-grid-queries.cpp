class DSU {
private:
    vector<int> parent, size;
    int n, m;
public:
    DSU(int a, int b) {
        n = a;
        m = b; 
        parent.resize(n * m, -1);
        size.resize(n * m, 1);
    }

    int find(int node) {
        if (parent[node] < 0) return node;
        return parent[node] = find(parent[node]);
    }

    bool unionFind(int x1, int x2, int y1, int y2) {
        int p1 = x1 * m + x2;  
        int p2 = y1 * m + y2;

        int rootA = find(p1);
        int rootB = find(p2);

        if (rootA == rootB) return false;

        if (size[rootA] > size[rootB]) {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        return true;
    }

    int getSize() {
        return size[find(0)];
    }
};

class Solution {
private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();

        vector<pair<int, int>> q(k);
        for (int i = 0; i < k; i++) {
            q[i] = {queries[i], i};
        }
        sort(q.begin(), q.end());

        DSU dsu(m, n);
        vector<int> ans(k);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.push({grid[i][j], {i, j}});
            }
        }

        for (auto [val, index] : q) {
            while (!pq.empty() && pq.top().first < val) {
                auto [x, i] = pq.top();
                pq.pop();
                int row = i.first;
                int col = i.second;

                for (auto &d : dir) {
                    int newRow = row + d[0];
                    int newCol = col + d[1];

                    if (newRow >= m || newRow < 0) continue;
                    if (newCol >= n || newCol < 0) continue;
                    if (grid[newRow][newCol] < val) {
                        dsu.unionFind(row, col, newRow, newCol);
                    }
                }
            }
            if(grid[0][0]>=val) ans[index]=0;
            else ans[index] = dsu.getSize();
        }
        return ans;
    }
};
