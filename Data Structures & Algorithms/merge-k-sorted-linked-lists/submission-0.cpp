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
    ListNode* mergeList(vector<ListNode*>& lists, int begin, int end) {
        if (end <= begin) {
            return lists[begin];
        }

        int mid = (begin + end) / 2;

        ListNode* l1 = mergeList(lists, begin, mid);
        ListNode* l2 = mergeList(lists, mid + 1, end);

        ListNode dummy;
        ListNode* head = &dummy;
        // Merge
        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                head -> next = l1;
                l1 = l1 -> next;
                head = head -> next;
            } else {
                head -> next = l2;
                l2 = l2 -> next;
                head = head -> next;
            }
        }

        if (l1)
            head -> next = l1;
        
        if (l2)
            head -> next = l2;


        return dummy.next;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        
        int n = lists.size() - 1;

        return mergeList(lists, 0, n);

    }
};
