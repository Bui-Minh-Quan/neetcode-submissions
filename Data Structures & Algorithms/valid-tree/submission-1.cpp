class Solution {
private:
    bool dfs(unordered_map<int, set<int>>& graph, vector<bool>& visited, int node, int prev = -1) {
        visited[node] = true;

        for (const auto& n:graph[node]) {
            if (n == prev)
                continue;

            if (visited[n]) {            
                return false;
            } 

            if (!dfs(graph, visited, n, node))
                return false;
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, set<int>> graph;
        vector<bool> visited(n, false);

        for (auto& e:edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        if (!dfs(graph, visited, 0))
            return false;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        
        return true;
    }
};
