class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;

        if (s1.length() > s2.length())
            return false;

        for (const auto& c:s1)
            mp[c]++;

        const int n1 = s1.length();
        const int n2 = s2.length();
        int chars_left = n1;

        for (int i = 0; i < n1; i++) {
            if (mp.find(s2[i]) != mp.end()) {
                if (mp[s2[i]] > 0)
                    chars_left--;
                mp[s2[i]]--; 
                
            }
        }

        if (chars_left == 0)
            return true;

        for (int i = n1; i < n2; i++) {
            if (chars_left == 0)
                return true;

            // add the next character to current window
            if (mp.find(s2[i]) != mp.end()) {
                if (mp[s2[i]] > 0)
                    chars_left--;
                mp[s2[i]]--;
                
            }

            // remove the left left character of the window
            if (mp.find(s2[i - n1]) != mp.end()) {
                mp[s2[i - n1]]++;

                if (mp[s2[i - n1]] > 0)
                    chars_left++;

            }
        }

        return chars_left == 0;

    }
};




