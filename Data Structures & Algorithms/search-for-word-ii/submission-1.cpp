class Solution {
private:
    struct TrieNode {
        TrieNode* next[26]{};
        string word;

        TrieNode() : word("") {}
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;

    void addWord(const string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int i = c - 'a';

            if (!node->next[i])
                node->next[i] = new TrieNode();

            node = node->next[i];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int x,
             int y,
             TrieNode* node) {

        // Out of bounds
        if (x < 0 || x >= board.size() ||
            y < 0 || y >= board[0].size()) {
            return;
        }

        // Already visited
        if (board[x][y] == '#')
            return;

        int index = board[x][y] - 'a';

        // No word has this prefix
        if (!node->next[index])
            return;

        node = node->next[index];

        // Found a complete word
        if (!node->word.empty()) {
            ans.push_back(node->word);

            // Prevent duplicate results
            node->word.clear();
        }

        // Mark visited
        char original = board[x][y];
        board[x][y] = '#';

        dfs(board, x - 1, y, node);
        dfs(board, x + 1, y, node);
        dfs(board, x, y - 1, node);
        dfs(board, x, y + 1, node);

        // Backtrack
        board[x][y] = original;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (const string& word : words)
            addWord(word);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};