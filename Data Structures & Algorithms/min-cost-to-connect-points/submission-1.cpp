class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> dis(n, INT_MAX);
        vector<bool> visited(n, false);

        dis[0] = 0;

        int current = 0;
        int count = 1;

        while (count < n) {
            visited[current] = true;

            int min_dis = INT_MAX;
            int next = -1;

            for (int i = 0; i < n; ++i) {
                if (visited[i])
                    continue;

                int distance =
                    abs(points[current][0] - points[i][0]) +
                    abs(points[current][1] - points[i][1]);

                dis[i] = min(dis[i], distance);

                if (dis[i] < min_dis) {
                    min_dis = dis[i];
                    next = i;
                }
            }

            current = next;
            ++count;
        }

        int ans = 0;

        for (int d : dis)
            ans += d;

        return ans;
    }
};