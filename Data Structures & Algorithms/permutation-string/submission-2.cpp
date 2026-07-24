class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> count(26);

        for (char c : s1)
            count[c - 'a']++;

        int charsLeft = s1.size();

        for (int right = 0; right < s2.size(); right++) {

            int in = s2[right] - 'a';

            if (count[in] > 0)
                charsLeft--;

            count[in]--;

            if (right >= s1.size()) {

                int out = s2[right - s1.size()] - 'a';

                count[out]++;

                if (count[out] > 0)
                    charsLeft++;
            }

            if (charsLeft == 0)
                return true;
        }

        return false;
    }
};