class Solution {
private:
    vector<vector<string>> ans;

    void backtrack(
        int row,
        int cols,
        int diag1,
        int diag2,
        int mask,
        vector<string>& board
    ) {
        int n = board.size();

        if (row == n) {
            ans.push_back(board);
            return;
        }

        int available = ~(cols | diag1 | diag2) & mask;

        while (available) {
            int bit = available & -available;
            available -= bit;

            // Convert bit position -> column
            int col = __builtin_ctz(bit);

            board[row][col] = 'Q';

            backtrack(
                row + 1,
                cols | bit,
                (diag1 | bit) << 1,
                (diag2 | bit) >> 1,
                mask,
                board
            );

            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();

        vector<string> board(n, string(n, '.'));

        int mask = (1 << n) - 1;

        backtrack(
            0,
            0,
            0,
            0,
            mask,
            board
        );

        return ans;
    }
};