/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {

            return nullptr;

        }

        

        ListNode *ptrA = headA;

        ListNode *ptrB = headB;

        

        // Traverse both lists

        while (ptrA != ptrB) {

            // Move to the next node, or to the beginning of the other list if reached end

            ptrA = (ptrA == nullptr) ? headB : ptrA->next;

            ptrB = (ptrB == nullptr) ? headA : ptrB->next;

        }

        

        // Either both are nullptr (no intersection) or both are at the intersection node

        return ptrA;
    }
};