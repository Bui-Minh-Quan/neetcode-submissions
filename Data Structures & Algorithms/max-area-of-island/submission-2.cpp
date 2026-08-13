class Solution {
private:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        // check valid position
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return 0;
        
        // Check if this is an island
        if (grid[x][y] == 0)
            return 0;
        
        // Mark current island as visited
        grid[x][y] = 0;

        return 1 + dfs(grid, x - 1, y) + dfs(grid, x + 1, y) + dfs(grid, x, y - 1) + dfs(grid, x, y + 1);

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;

        const int m = grid.size();
        const int n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    int new_area = dfs(grid, i, j);

                    max_area = max(max_area, new_area);
                }

        return max_area;
    }
};
