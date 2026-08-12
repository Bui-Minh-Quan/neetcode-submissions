struct Node{
    Node* next[26];
    bool isEnd;

    Node() {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
        
        isEnd = false;
    }
};

class WordDictionary {
private:
    Node* root;

    bool helper(string& word, int index, Node* node) {
        if (index == word.length()) {
            return node != nullptr && node -> isEnd;
        }
        
        if (node == nullptr)
            return false;
        
        // Case 1: Normal letter
        if (word[index] != '.') {
            int i = word[index] - 'a';

            if (node -> next[i] == nullptr)
                return false;
            
            return helper(word, index + 1, node -> next[i]);
        }

        // Case 2: A dot '.'
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++)
                if (helper(word, index + 1, node -> next[i]))
                    return true;
        }

        return false;
    }


public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (const auto& c:word) {
            int index = c - 'a';

            if (node -> next[index] == nullptr)
                node -> next[index] = new Node();
            
            node = node -> next[index];
        }

        node -> isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        return helper(word, 0, node);
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (const auto& c:prefix) {
            int index = c - 'a';
            
            if (node -> next[index] == nullptr)
                return false;
            
            node = node -> next[index];
        }

        return true;
    }
};


class Solution {
private:
    WordDictionary dict;
    vector<string> ans;

    void backtrack(vector<vector<char>>& board,
               string curr,
               int x,
               int y) {

    if (x < 0 || x >= board.size() ||
        y < 0 || y >= board[0].size())
        return;

    if (board[x][y] == '*')
        return;

    char origin = board[x][y];

    string new_curr = curr + origin;

    // No word starts with this prefix
    if (!dict.startsWith(new_curr))
        return;

    // Found a word
    if (dict.search(new_curr)) {
        if (find(ans.begin(), ans.end(), new_curr) == ans.end()) {
            ans.push_back(new_curr);
        }
    }

    // Mark visited
    board[x][y] = '*';

    backtrack(board, new_curr, x - 1, y);
    backtrack(board, new_curr, x + 1, y);
    backtrack(board, new_curr, x, y - 1);
    backtrack(board, new_curr, x, y + 1);

    // Restore
    board[x][y] = origin;
}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        

        for (const auto& word:words)
            dict.addWord(word);

        const int m = board.size();
        const int n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                backtrack(board, "", i, j);
            }

        return ans;
    }
};





















