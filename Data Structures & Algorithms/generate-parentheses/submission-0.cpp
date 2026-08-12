class Solution {
private:
    vector<string> ans;
    void backtrack(string curr, int left, int right) {
        if (left == 0 && right == 0) {
            ans.push_back(curr);
            return;
        }

        if (left > 0) {
            backtrack(curr + '(', left - 1, right);
        }

        if (right > left) {
            backtrack(curr + ')', left, right - 1);
        }
    }



public:
    vector<string> generateParenthesis(int n) {
        backtrack("", n, n);

        return ans;
    }
};
