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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the head of the merged list.

        ListNode dummy;

        ListNode* tail = &dummy;

        // Traverse both lists until one of them is empty.

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val < list2->val) {

                tail->next = list1;    // Append the smaller node to the merged list.

                list1 = list1->next;   // Move the pointer of the list from which the node was taken.

            } else {

                tail->next = list2;    // Append the smaller node to the merged list.

                list2 = list2->next;   // Move the pointer of the list from which the node was taken.

            }

            tail = tail->next;         // Move the tail pointer to the newly added node.

        }

        // Append the remaining nodes of list1 or list2.

        if (list1 != nullptr) {

            tail->next = list1;

        } else {

            tail->next = list2;

        }
        return dummy.next;
    }
};