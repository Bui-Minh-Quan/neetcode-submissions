class Solution {
private:
    vector<string> ans;

    void backtracking(string& digits, string current_string, unordered_map<char, string>& d2s) {
        if (current_string.length() > digits.length()) return;

        
        if (current_string.length() < digits.length()) {
            int pos = current_string.length();
            string temp = d2s[digits[pos]];
            for (char c:temp) {
                backtracking(digits, current_string + c, d2s);
            }
            return;
        }

        ans.push_back(current_string);

    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};
        unordered_map<char, string> d2s;

        d2s['2'] = "abc";
        d2s['3'] = "def";
        d2s['4'] = "ghi";
        d2s['5'] = "jkl";
        d2s['6'] = "mno";
        d2s['7'] = "pqrs";
        d2s['8'] = "tuv";
        d2s['9'] = "wxyz";

        backtracking(digits, "", d2s);

        return ans;





    }
};