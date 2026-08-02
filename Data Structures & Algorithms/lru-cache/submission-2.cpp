struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key = 0, int value = 0)
        : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;

    // Dummy nodes
    Node head;
    Node tail;

    // Remove node from the linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right before tail (MRU position)
    void insertNode(Node* node) {
        node->prev = tail.prev;
        node->next = &tail;

        tail.prev->next = node;
        tail.prev = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head.next = &tail;
        tail.prev = &head;

        cache.reserve(capacity);
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        Node* node = it->second;

        removeNode(node);
        insertNode(node);

        return node->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        // Key already exists
        if (it != cache.end()) {
            Node* node = it->second;
            node->value = value;

            removeNode(node);
            insertNode(node);
            return;
        }

        // Cache full -> evict LRU
        if (cache.size() == capacity) {
            Node* lru = head.next;

            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }

        // Insert new node
        Node* node = new Node(key, value);

        insertNode(node);
        cache[key] = node;
    }

    ~LRUCache() {
        Node* curr = head.next;

        while (curr != &tail) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};