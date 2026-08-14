#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Min-heap priority_queue ensures lexicographically smallest neighbor is processed first
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> itinerary;

    void dfs(const string& airport) {
        // While there are outgoing edges from the current airport
        while (graph.count(airport) && !graph[airport].empty()) {
            string next_airport = graph[airport].top();
            graph[airport].pop(); // Use the ticket (remove edge)
            dfs(next_airport);
        }
        // Post-order insertion: add airport once all outgoing tickets are used
        itinerary.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 1. Build adjacency list with min-heaps
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        // 2. Start Eulerian path traversal from "JFK"
        dfs("JFK");

        // 3. Reconstruct correct order from post-order DFS
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};