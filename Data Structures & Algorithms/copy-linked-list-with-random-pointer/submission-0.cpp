/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        Node* h = head;
        

        // 1. Duplicate list
        while (head) {
            Node* new_node = new Node(head -> val);

            new_node -> next = head -> next;
            head -> next = new_node;

            head = new_node -> next;
        }

       
        // 2. Assign random
        head = h;

        while (head) {
            Node* new_node = head -> next;

            if (head -> random == nullptr)
                new_node -> random = nullptr;
            else 
                new_node -> random = head -> random -> next;
            
            head = new_node -> next;
        }


        // 3. Separate list
        head = h;
        Node* new_h = head -> next;
        Node* new_node = head -> next;


        while (head != nullptr) {

            head -> next = new_node -> next;

            head = head -> next;

            if (head)
                new_node -> next = head -> next;
            else 
                new_node -> next = nullptr;

            new_node = new_node -> next;
        }


        return new_h;

    }
};























