class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int max_freq = 0;
        int ans = 0;

        const int n = s.length();
        for (int right = 0; right < n; right++) {
            count[s[right] - 'A']++;
            max_freq = max(max_freq, count[s[right] - 'A']);

            while ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        


        return ans;
    }
};





