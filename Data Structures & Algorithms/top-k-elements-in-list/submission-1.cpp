class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums)
            ++freq[num];

        // bucket[i] contains numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &[num, count] : freq)
            bucket[count].push_back(num);

        vector<int> ans;
        ans.reserve(k);

        // Traverse from highest frequency to lowest
        for (int f = nums.size(); f >= 1 && ans.size() < k; --f) {
            for (int num : bucket[f]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};