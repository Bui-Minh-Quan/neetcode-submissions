class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> mp;

        int left = 0, right = 0;
        int ans = 0;

        const int n = s.length();

        while (right < n) {
            if (mp.find(s[right]) == mp.end() || mp[s[right]] == false) {
                mp[s[right]] = true;
                ++right;
                ans = max(ans, right - left);
            } else {
                mp[s[left]] = false;
                ++left;
                right = max(left, right);
            }
        }

        return ans;
    }
};
