class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        const int rows = grid.size();
        const int cols = grid[0].size();

        int maxArea = 0;

        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {

                if (grid[r][c] == 0)
                    continue;

                int area = 0;
                stack<pair<int, int>> st;
                st.push({r, c});
                grid[r][c] = 0;

                while (!st.empty()) {
                    auto [cr, cc] = st.top();
                    st.pop();

                    ++area;

                    for (int d = 0; d < 4; ++d) {
                        int nr = cr + dr[d];
                        int nc = cc + dc[d];

                        if (nr >= 0 && nr < rows &&
                            nc >= 0 && nc < cols &&
                            grid[nr][nc] == 1) {

                            grid[nr][nc] = 0;
                            st.push({nr, nc});
                        }
                    }
                }

                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};