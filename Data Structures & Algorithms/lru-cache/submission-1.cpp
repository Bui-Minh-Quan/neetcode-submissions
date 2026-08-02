struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int value;
    int key;

    Node() {
        value = 0;
        key = 0;
        next = nullptr;
        prev = nullptr;
    }
    
    Node (int value, int key) {
        this -> value = value;
        this -> key = key;
        prev = nullptr;
        next = nullptr;
    }

    Node(int value, int key, Node* prev, Node* next) {
        this -> value = value;
        this -> key = key;
        this -> prev = prev;
        this -> next = next;
    }

    
};

class LRUCache {
private:
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int capacity;

    void remove_node(Node* node) {
        if (!node)
            return;

        mp.erase(node -> key);

        Node* prev = node -> prev;
        prev -> next = node -> next;
        node -> next -> prev = prev;
    }

    void add_node(Node* node) {
        if (!node)
            return;
        
        mp[node -> key] = node;

        node -> next = tail;
        node -> prev = tail -> prev;

        tail -> prev -> next = node;
        tail -> prev = node;

    }

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> head = new Node();
        this -> tail = new Node();

        this -> head -> next = tail;
        this -> tail -> prev = head;
    }
    
    int get(int key) {
        if (!mp.contains(key))
            return -1;

        Node* node = mp[key];
        
        remove_node(node);
        add_node(node);

        return node -> value;
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            Node* node = mp[key];
            node -> value = value;

            remove_node(node);
            add_node(node);

            return;
        }

        while (mp.size() >= capacity) {
            Node* delete_node = head -> next;
            if (delete_node == tail)
                break;
            
            remove_node(delete_node);

            delete_node = nullptr;
            delete delete_node;
        }

        Node* new_node = new Node(value, key);

        add_node(new_node);
    }
};





