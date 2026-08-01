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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy;
        ListNode* l = &dummy;

        while (l1 && l2) {
            l -> next = l1;
            l1 -> val += l2 -> val + carry;
            carry = l1 -> val / 10;
            l1 -> val %= 10;

            l1 = l1 -> next;
            l2 = l2 -> next;

            l = l -> next;
        }

        while (l1) {
            l -> next = l1;
            l1 -> val += carry;
            carry = l1 -> val / 10;
            l1 -> val %= 10;
            
            l1 = l1 -> next;

            l = l -> next;
        }

        while (l2) {
            l -> next = l2;
            l2 -> val += carry;
            carry = l2 -> val / 10;
            l2 -> val %= 10;

            l2 = l2 -> next;

            l = l -> next;
        }

        if (carry)
            l -> next = new ListNode(1);

        

        
        return dummy.next;
    }
};
