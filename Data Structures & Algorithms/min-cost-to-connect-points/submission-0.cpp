class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> dis(n, INT_MAX);
        vector<bool> visited(n, false);

        dis[0] = 0;


        vector<int> nodes;
        nodes.push_back(0);

        while (nodes.size() < n) {
            int current = nodes.back();
            visited[current] = true;

            int min_dis = INT_MAX;
            int next = -1;

            for (int i = 0; i < n; i++) {
                if (visited[i])
                    continue;
                
                int p_x = points[i][0];
                int p_y = points[i][1];

                int new_dis = abs(points[current][0] - p_x) + abs(points[current][1] - p_y);

                if (new_dis < dis[i])
                    dis[i] = new_dis;

                if (dis[i] < min_dis) {
                    min_dis = dis[i];
                    next = i;
                }
            }
            if (next == -1)
                break;
            nodes.push_back(next);
        }

        int ans = 0;

        for (const auto& d:dis)
            ans += d;

        return ans;
        
    }
};
