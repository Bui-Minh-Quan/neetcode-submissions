class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> degree(numCourses, 0);
        queue<int> q;

        vector<int> ans;

        for (const auto& p:prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++degree[p[0]];
        }

        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0)
                q.push(i);

        }

        while (!q.empty()) {
            
            int s = q.front();
            q.pop();

            ans.push_back(s);

            for (auto& c:graph[s]) {
                --degree[c];
                if (degree[c] == 0) {
                    q.push(c);
                }
            }
        }

        vector<int> empty;
        return ans.size() == numCourses ? ans:empty;
        
    }
};
