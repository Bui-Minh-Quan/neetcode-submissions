struct Node{
    Node* next[26];
    bool isEnd;

    Node() {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
        
        isEnd = false;
    }
};

class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
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

        for (const auto& c:word) {
            int index = c - 'a';
            
            if (node -> next[index] == nullptr)
                return false;
            
            node = node -> next[index];
        }

        return node -> isEnd;
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



















