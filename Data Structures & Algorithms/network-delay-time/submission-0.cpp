class Solution {
private:
    vector<int> dis;

    void dfs(unordered_map<int, vector<pair<int, int>>>& graph, int node, int curr_dis) {
        
        for (const auto& n:graph[node]) {
            int target = n.first;
            int time = n.second;

            if (curr_dis + time >= dis[target])
                continue;
            
            dis[target] = curr_dis + time;

            dfs(graph, target, curr_dis + time);
        }
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;

        dis.resize(n + 1, INT_MAX); // Time it takes from node start to any node

        // Make the graph
        for (const auto& t:times) {
            int source = t[0];
            int target = t[1];
            int time = t[2];

            graph[source].push_back({target, time});
        }

        int ans = INT_MIN;

        dis[k] = 0;

        dfs(graph, k, 0);

        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) {
                return -1;
            }
            
            ans = max(ans, dis[i]);
        }
  
    

        return ans;
        

    }
};
