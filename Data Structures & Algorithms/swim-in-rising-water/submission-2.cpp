template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        min_heap<tuple<int, int, int>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        const int dx[] = {0, -1, 0, 1};
        const int dy[] = {-1, 0, 1, 0};

        int ans = 0;

        while (!pq.empty()) {
            auto [level, x, y] = pq.top();
            pq.pop();

            ans = max(ans, level);

            if (x == m - 1 && y == n - 1)
                return ans;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n)
                    continue;

                if (visited[nx][ny])
                    continue;

                visited[nx][ny] = true;
                pq.push({grid[nx][ny], nx, ny});
            }
        }

        return -1;
    }
};