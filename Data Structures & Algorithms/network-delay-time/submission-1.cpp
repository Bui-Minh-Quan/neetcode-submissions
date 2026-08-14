#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Vector-based adjacency list: graph[u] = {{v, w}, ...}
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        // Distance vector initialized to infinity
        vector<int> dis(n + 1, INT_MAX);

        // Min-heap storing pair<distance, node>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start at node k with distance 0
        dis[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [curr_dis, u] = pq.top();
            pq.pop();

            // Skip stale entries with larger distances
            if (curr_dis > dis[u]) continue;

            for (const auto& [v, weight] : graph[u]) {
                if (curr_dis + weight < dis[v]) {
                    dis[v] = curr_dis + weight;
                    pq.push({dis[v], v});
                }
            }
        }

        // 2. Find the maximum signal travel time
        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dis[i] == INT_MAX) return -1; // Unreachable node
            max_time = max(max_time, dis[i]);
        }

        return max_time;
    }
};