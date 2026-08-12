class Solution {
private:
    vector<string> temp;
    vector<vector<string>> ans;

    bool check(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) 
                return false;
            
            ++left;
            --right;
        }

        return true;
    }

    void backtrack(string& s, int index) {
        if (index == s.length()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (!check(s, index, i)) 
                continue;
            
            temp.push_back(s.substr(index, i - index + 1));

            backtrack(s, i + 1);

            temp.pop_back();
        }


    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);

        return ans;
    }
};







































