class Solution {
private:
    vector<vector<string>> ans;

    void backtrack(
        vector<string>& board,
        vector<bool>& cols,
        vector<bool>& diag1,
        vector<bool>& diag2,
        int x
    ) {
        if (x == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int y = 0; y < board.size(); y++) {

            // \ diagonal: x - y
            // + n - 1 makes the index non-negative
            int d1 = x - y + board.size() - 1;

            // / diagonal: x + y
            int d2 = x + y;

            if (cols[y] || diag1[d1] || diag2[d2])
                continue;

            // Place queen
            board[x][y] = 'Q';
            cols[y] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            backtrack(
                board,
                cols,
                diag1,
                diag2,
                x + 1
            );

            // Backtrack
            board[x][y] = '.';
            cols[y] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);

        // There are 2n - 1 diagonals in each direction
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(board, cols, diag1, diag2, 0);

        return ans;
    }
};