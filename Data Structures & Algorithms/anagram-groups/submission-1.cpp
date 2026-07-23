// Fast I/O trick
auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        // Reserve bucket space to avoid map re-hashing overhead
        mp.reserve(strs.size());

        for (const string& str : strs) {
            // Count frequency of each letter
            int count[26] = {0};
            for (char c : str) {
                count[c - 'a']++;
            }

            // Build a unique key string based on character counts
            string key = "";
            for (int i = 0; i < 26; ++i) {
                if (count[i] > 0) {
                    key += string(1, 'a' + i) + to_string(count[i]);
                }
            }

            // Single hash lookup!
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        // Use std::move to prevent deep copying of string vectors
        for (auto& [key, value] : mp) {
            ans.push_back(move(value));
        }

        return ans;
    }
};