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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;


        while (curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }


    void reorderList(ListNode* head) {
        if (head -> next == nullptr)
            return;
        ListNode* mid = head;
        ListNode* fast = head;

        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;


        ListNode* left_half = head;
        ListNode* right_half = reverseList(mid);



        ListNode dummy;
        ListNode* h = &dummy;

        int i = 0;
        while (left_half && right_half) {
            h -> next = left_half;
            left_half = left_half -> next;

            h = h -> next;

            h -> next = right_half;
            right_half = right_half -> next;

            h = h -> next;
        }

        if (left_half)
            h -> next = left_half;
        
        if (right_half)
            h -> next = right_half;
    }
};









