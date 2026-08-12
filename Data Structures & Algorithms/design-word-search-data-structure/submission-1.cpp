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
};
