class Solution {
private:
    int count = 0;
    void count_from_center(string& s, int left, int right, int n) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            ++count;
            --left;
            ++right;
        }
    }

public:

    int countSubstrings(string s) {
        const int n = s.length();
        for (int i = 0; i < n; i++) {
            // odd center
            count_from_center(s, i, i, n);
            // even center
            count_from_center(s, i, i + 1, n);
        }

        return count;
    }
};
