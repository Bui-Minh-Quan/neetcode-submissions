class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int min_cost = INT_MAX;

        cost.push_back(0);
        const int n = cost.size();

        vector<int> arr(n + 1);

        arr[0] = cost[0];
        arr[1] = cost[1];

        for (int i = 2; i < n; i++) 
            arr[i] = cost[i] + min(arr[i - 1], arr[i - 2]);
        
        return arr[n - 1];
    }
};
