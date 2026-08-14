template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        min_heap<tuple<int, int, int>> pq;
        map<pair<int, int>, bool> visited;

        pq.push({grid[0][0], 0, 0});

        int ans = grid[0][0];
        visited[{0, 0}] = true;

        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};

        const int m = grid.size();
        const  int n = grid[0].size();

        while (!pq.empty()) {
            auto[level, x, y] = pq.top();
            pq.pop();

            ans = max(ans, level);

            if (x == m - 1 && y == n - 1)
                return ans;

            
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                // Check valid position
                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
                    continue;


                // Check if visit before
                if (visited[{new_x, new_y}])
                    continue;
                
                visited[{new_x, new_y}] = true;
                pq.push({grid[new_x][new_y], new_x, new_y});


            }

        }

        return ans;
    }
};














