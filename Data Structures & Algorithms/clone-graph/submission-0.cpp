/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        if (mp.contains(node))
            return mp[node];
        
        Node* new_node = new Node();

        new_node -> val = node -> val;

        mp[node] = new_node;

        for (const auto& neighbor:node->neighbors) {
            if (mp.contains(neighbor))
                new_node -> neighbors.push_back(mp[neighbor]);
            else 
                new_node -> neighbors.push_back(cloneGraph(neighbor));
        }

        return new_node;
    }
};


















