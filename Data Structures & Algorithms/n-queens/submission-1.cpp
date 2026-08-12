#include <vector>
#include <string>

class Solution {
private:
    std::vector<std::vector<std::string>> ans;
    int N;

    void backtrack(int row, int cols, int diag1, int diag2, std::vector<int>& queens) {
        // Base case: All queens successfully placed
        if (row == N) {
            std::vector<std::string> board(N, std::string(N, '.'));
            for (int r = 0; r < N; ++r) {
                board[r][queens[r]] = 'Q';
            }
            ans.push_back(board);
            return;
        }

        // Get bitmask of all available positions for the current row
        int available = ((1 << N) - 1) & ~(cols | diag1 | diag2);

        while (available) {
            // Isolate the lowest set bit (pick the first available spot)
            int p = available & -available;
            
            // Clear the lowest set bit for the next iteration
            available &= available - 1;

            // Convert bitmask position to column index
            int col = __builtin_ctz(p);

            queens[row] = col;

            // Recurse to next row:
            // - cols | p: mark column as occupied
            // - (diag1 | p) << 1: shift \ diagonal restriction left for next row
            // - (diag2 | p) >> 1: shift / diagonal restriction right for next row
            backtrack(row + 1, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, queens);
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        N = n;
        std::vector<int> queens(n);
        
        backtrack(0, 0, 0, 0, queens);
        
        return ans;
    }
};