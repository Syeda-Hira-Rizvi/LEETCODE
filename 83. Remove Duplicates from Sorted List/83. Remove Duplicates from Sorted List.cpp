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
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) return head;

        

        ListNode* current = head;

        

        while (current != nullptr && current->next != nullptr) {

            if (current->val == current->next->val) {

                // Skip the next node since it's a duplicate

                current->next = current->next->next;

            } else {

                // Move to the next node

                current = current->next;

            }

        }

        

        return head;  
    }
};