class Solution {
private:
    int count = 0;
    void count_from_center(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            ++count;
            --left;
            ++right;
        }
    }

public:

    int countSubstrings(string s) {
        
        for (int i = 0; i < s.length(); i++) {
            // odd center
            count_from_center(s, i, i);
            // even center
            count_from_center(s, i, i + 1);
        }

        return count;
    }
};
