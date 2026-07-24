class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<int> min_prices(n, 0);
        vector<int> max_prices(n, 0);

        min_prices[0] = prices[0];
        max_prices[n - 1] = prices[n - 1];

        for (int i = 1; i < n; i++) {
            if (prices[i] < min_prices[i - 1])
                min_prices[i] = prices[i];
            else 
                min_prices[i] = min_prices[i - 1];
            
            if (prices[n - i - 1] > max_prices[n - i])
                max_prices[n - i - 1] = prices[n - i - 1];
            else
                max_prices[n - i - 1] = max_prices[n - i];

        }

        int ans = 0;

        for (int i = 0; i < n; i++)
            ans = max(ans, max_prices[i] - min_prices[i]);
        return ans;
    }
};
