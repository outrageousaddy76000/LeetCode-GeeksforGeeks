class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        //greate graph
        map <pair<int,int>, vector <vector<int>>> m;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i>0) m[make_pair(i,j)].push_back({i-1,j,grid[i][j]==4?0:1});
                if(i<grid.size()-1) m[make_pair(i,j)].push_back({i+1,j,grid[i][j]==3?0:1});
                if(j>0) m[make_pair(i,j)].push_back({i,j-1,grid[i][j]==2?0:1});
                if(j<grid[0].size()-1) m[make_pair(i,j)].push_back({i,j+1,grid[i][j]==1?0:1});
            }
        }
        //perform bfs from 0,0
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        deque<pair<int, int>> dq;

        // Initialize BFS
        dq.push_front({0, 0});
        distance[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (auto& neighbor : m[{x, y}]) {
                int nx = neighbor[0], ny = neighbor[1], cost = neighbor[2];
                if (!visited[nx][ny] && distance[x][y] + cost < distance[nx][ny]) {
                    distance[nx][ny] = distance[x][y] + cost;
                    if (cost == 0) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }

        int ans = distance[grid.size() - 1][grid[0].size() - 1];
        return ans == INT_MAX ? -1 : ans;
    }
};