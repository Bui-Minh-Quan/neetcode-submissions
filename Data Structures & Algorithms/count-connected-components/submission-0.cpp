class Solution {
private:

    void dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int node) {
        if (visited[node])
            return;
        
        visited[node] = true;

        for (const auto& n:graph[node]) {
            dfs(graph, visited, n);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> graph;

        // Make graph
        for (const auto& e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ++ans;
                dfs(graph, visited, i);
            }
        }

        return ans;
    }
};
