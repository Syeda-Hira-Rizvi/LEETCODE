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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;

        ListNode* fast = head;

        // Move slow pointer by 1 step and fast pointer by 2 steps

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;

            fast = fast->next->next;

        }

        return slow; // When fast reaches the end, slow will be at the middle
    }
};