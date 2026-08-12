class Solution {
private:
    bool backtrack(vector<vector<char>>& board, string& word, int x, int y, int index) {
        if (index >= word.length())
            return true;
        

        // check valid position
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;
        
        // check visited
        if (board[x][y] == '*')
            return false;

        // check target
        if (board[x][y] != word[index])
            return false;

        char origin = board[x][y];
        board[x][y] = '*';
        
        bool r1 = backtrack(board, word, x - 1, y, index + 1);
        bool r2 = backtrack(board, word, x + 1, y, index + 1);
        bool r3 = backtrack(board, word, x, y - 1, index + 1);
        bool r4 = backtrack(board, word, x, y + 1, index + 1);

        board[x][y] = origin;

        return r1 || r2 || r3 || r4;
    }


public:
    bool exist(vector<vector<char>>& board, string word) {
        char target = word[0];

        const int m = board.size();
        const int n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] != target)
                    continue;
                
                bool check = backtrack(board, word, i, j, 0);
                if (check)
                    return true;
            }

        return false;
    }
};




