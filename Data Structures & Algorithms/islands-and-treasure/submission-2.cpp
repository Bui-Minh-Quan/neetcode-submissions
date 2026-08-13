class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        queue<pair<int, int>> q;

        // Add all treasures to the queue
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Out of bounds
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                // Wall
                if (grid[nr][nc] == -1)
                    continue;

                // Already processed
                if (grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};