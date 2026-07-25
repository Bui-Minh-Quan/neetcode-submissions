class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";

        vector<int> count(300, 0);

        for (const auto& c:t)
            count[c - 'A']++;
        
        int target = t.length();
        int left = 0, right = 0;
        int min_range = -1;

        const int n = s.length();

        for (int i = 0; i < n; i++) {
            if (count[s[i] - 'A'] > 0) {
                target--;
            }


            count[s[i] - 'A']--;

            if (target > 0)
                continue;

            while (target <= 0 && left <= i) {
            if (i - left + 1 < min_range || min_range == -1) {
                right = i;
                min_range = i - left + 1;
            }

            count[s[left] - 'A']++;

            if (count[s[left] - 'A'] > 0)
                target++;

            ++left;
            }
        }

        if (min_range == -1)
            return "";

        
        return s.substr(right - min_range + 1, min_range);
    }
};
