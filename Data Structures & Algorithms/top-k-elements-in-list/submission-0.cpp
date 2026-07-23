class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n <= 1) 
            return {nums[0]};
        
        unordered_map<int, int> freq;

        for (const auto& num:nums)
            freq[num]++;

        priority_queue<pair<int, int>> pq; // [freq, number]

        for (const auto& [key, value]:freq) 
            pq.push({value, key});

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int value = pq.top().second;
            pq.pop();
            ans.push_back(value);
        }

        return ans;
    }
};
