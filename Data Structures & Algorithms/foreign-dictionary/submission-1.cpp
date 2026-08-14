class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, int> in_degree;
        unordered_map<char, unordered_set<char>> graph;

        // Every character must appear in the result.
        for (const string& word : words) {
            for (char c : word) {
                in_degree[c] = 0;
            }
        }

        // Build edges from adjacent words.
        for (int i = 0; i + 1 < words.size(); ++i) {
            string& a = words[i];
            string& b = words[i + 1];

            int len = min(a.size(), b.size());
            int j = 0;

            while (j < len && a[j] == b[j])
                ++j;

            // Invalid:
            // ["abc", "ab"]
            if (j == len) {
                if (a.size() > b.size())
                    return "";
                
                continue;
            }

            char from = a[j];
            char to = b[j];

            // Only increment indegree for a NEW edge.
            if (graph[from].insert(to).second) {
                ++in_degree[to];
            }
        }

        // Topological sort
        queue<char> q;

        for (auto& [c, degree] : in_degree) {
            if (degree == 0)
                q.push(c);
        }

        string ans;

        while (!q.empty()) {
            char c = q.front();
            q.pop();

            ans += c;

            for (char next : graph[c]) {
                if (--in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If we couldn't process every character,
        // there is a cycle.
        if (ans.size() != in_degree.size())
            return "";

        return ans;
    }
};