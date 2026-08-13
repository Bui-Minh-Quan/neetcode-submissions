class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int target = 0;
        
        queue<pair<int, int>> q;

        const int m = grid.size();
        const int n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1)
                    ++target;
            }
        
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        int ans = -1;
        while (!q.empty()) {
            int num = q.size();
            ++ans;

            for (int i = 0; i < num; i++) {
                auto[x, y] = q.front();
                q.pop();

                
                for (int j = 0; j < 4; j++) {
                    int new_x = x + dx[j];
                    int new_y = y + dy[j];

                    if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
                        continue;
                    
                    
                    if (grid[new_x][new_y] != 1)
                        continue;
                    
                    
                    grid[new_x][new_y] = 2;
                    --target;

                    q.push({new_x, new_y});
                }

            }
        }

        if (target == 0)
            return max(ans, 0);
        
        return -1;
    }
};











