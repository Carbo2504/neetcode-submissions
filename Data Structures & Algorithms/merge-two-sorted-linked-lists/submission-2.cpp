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
    void printList(ListNode *head) {
        ListNode *node = head;
        while (node != nullptr) {
            cout << node->val;
            node = node->next;
        }
        cout << '\n';
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head = {};
        ListNode *current;

        current = &head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        if (list1 != nullptr) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }

        return head.next;
    }
};
