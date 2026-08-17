class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0, r = 0;
        int longest = INT_MIN;
        const int n = s.length();

        // odd center
        for (int i = 0; i < s.length(); i++) {
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left > longest) {
                    l = left;
                    r = right;
                    longest = right - left;
                }

                --left;
                ++right; 
            }
        }

        // even center
        for (int i = 0; i < s.length() - 1; i++) {

            int left = i;
            int right = i + 1;
            cout << s[left] << " " << s[right] << endl;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left > longest) {
                    l = left;
                    r = right;
                    longest = right - left;
                }
                --left;
                ++right;
            }
        }

        string ans;
        for (int i = l; i <= r; i++)
            ans += s[i];

        return ans;
    }
};



