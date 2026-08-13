#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return;
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // 1. Push all treasure locations (0s) into the queue at once
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Standard directions for up, down, left, right
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 2. Perform Multi-Source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Boundary check
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Skip obstacles (-1) or cells that already have a shorter/equal distance
                // INF is typically represented by 2,147,483,647 (INT_MAX)
                if (grid[nr][nc] <= grid[r][c] + 1)
                    continue;

                // Update distance and push to queue
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};