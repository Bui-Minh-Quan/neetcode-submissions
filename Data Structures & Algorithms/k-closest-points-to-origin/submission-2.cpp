class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<double>> pq;

        for (const auto& p:points) {
            double dis = sqrt((p[0] * p[0]) + (p[1] * p[1]));
            pq.push({dis,(double)p[0], (double)p[1]});
        }

        while (pq.size() > k)
            pq.pop();
        
        vector<vector<int>> ans;

        while (!pq.empty()) {
            vector<double> temp = pq.top();
            ans.push_back({(int)temp[1], (int)temp[2]});
            pq.pop();
        }

        return ans;
    }
};
