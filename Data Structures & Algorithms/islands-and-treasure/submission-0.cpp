class Solution {
private:
    void bfs(vector<vector<int>>& grid, int x, int y) {
        // Check valid position
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        
        if (grid[x][y] != 0)
            return;
        
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        
        int dis = 0;
        pair<int, int> moves[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        q.push({x, y});

        while (!q.empty()) {
            int n = q.size();
            ++dis;
            for (int i = 0; i < n; i++) {
                auto[pos_x, pos_y] = q.front();
                q.pop();
                for (const auto& move:moves) {
                    int new_pos_x = pos_x + move.first;
                    int new_pos_y = pos_y + move.second;

                    if (new_pos_x < 0 || new_pos_x >= grid.size())
                        continue;
                    
                    if (new_pos_y < 0 || new_pos_y >= grid[0].size())
                        continue;
                    
                    if (grid[new_pos_x][new_pos_y] == -1)
                        continue;
                    
                    if (visited.contains({new_pos_x, new_pos_y}))
                        continue;

                    if (grid[new_pos_x][new_pos_y] <= dis)
                        continue;

                    grid[new_pos_x][new_pos_y] = dis;

                    visited.insert({new_pos_x, new_pos_y});
                    q.push({new_pos_x, new_pos_y});
                }
            }

            

        }

    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 0)
                    bfs(grid, i, j);
    }
};









