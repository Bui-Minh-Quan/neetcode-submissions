class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        sort(nums.begin(), nums.end());
        for (const auto& num:nums) {
            mp[num] = mp[num - 1] + 1;
            ans = max(ans, mp[num]);
        }

        return ans;
        
    }
};
