/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reverseList(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* curr = head -> next;
        ListNode* next = nullptr;

        if (curr == nullptr)
            return;

        ListNode* h = curr;

        while (curr != tail) {
            next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
        }

        head -> next = prev;
        h -> next = tail;

        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = dummy;

        while (right) {
            for (int i = 0; i < k; i++)
                if (right)
                    right = right -> next;
                else
                    break;
            
            if (right == nullptr)
                break;
            
            ListNode* next_right = left -> next;
            //right -> next = nullptr;

            reverseList(left, right -> next);


            left = next_right;
            right = next_right;

        }

        

        return dummy -> next;
    }
};


