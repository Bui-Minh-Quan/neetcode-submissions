class Solution {
private:
    void bfs(
        vector<vector<int>>& heights,
        vector<vector<bool>>& visited,
        queue<pair<int, int>>& q
    ) {
        const int rows = heights.size();
        const int cols = heights[0].size();

        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Out of bounds
                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols)
                    continue;

                // Already visited
                if (visited[nr][nc])
                    continue;

                // Reverse water-flow condition
                if (heights[nr][nc] < heights[r][c])
                    continue;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int rows = heights.size();
        const int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        // Pacific: top + left
        for (int r = 0; r < rows; ++r) {
            pacific[r][0] = true;
            pacificQueue.push({r, 0});
        }

        for (int c = 0; c < cols; ++c) {
            pacific[0][c] = true;
            pacificQueue.push({0, c});
        }

        // Atlantic: bottom + right
        for (int r = 0; r < rows; ++r) {
            atlantic[r][cols - 1] = true;
            atlanticQueue.push({r, cols - 1});
        }

        for (int c = 0; c < cols; ++c) {
            atlantic[rows - 1][c] = true;
            atlanticQueue.push({rows - 1, c});
        }

        // Find cells that can reach each ocean
        bfs(heights, pacific, pacificQueue);
        bfs(heights, atlantic, atlanticQueue);

        // Find cells that can reach BOTH
        vector<vector<int>> result;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};