class Solution {
public:
    bool isAlphabet(char& c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }



    bool isPalindrome(string s) {
        const int n = s.length();
        int left = 0, right = n - 1;

        for (char &c : s) {
        c = std::tolower(static_cast<unsigned char>(c));
        }


        
        while (left < right) {
            while (left < right && !isAlphabet(s[left]))
                ++left;
            
            while (right > left && !isAlphabet(s[right]))
                --right;
            
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }

        return true;

    }
};
