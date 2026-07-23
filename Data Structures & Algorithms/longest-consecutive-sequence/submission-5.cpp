// Fast I/O optimization
auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Reserve space to eliminate hash table rehashing overhead
        unordered_set<int> st;
        st.reserve(nums.size());
        st.insert(nums.begin(), nums.end());

        int ans = 0;

        for (int num : st) { // Iterate over st instead of nums to avoid duplicate start checks
            // Only start counting if 'num' is the beginning of a sequence
            if (!st.count(num - 1)) {
                int current_num = num;
                int length = 1;

                while (st.count(current_num + 1)) {
                    current_num += 1;
                    length += 1;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};