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

        ListNode* current = head;

        

        while (current != nullptr) {

            ListNode* nextNode = current->next; // Store the next node

            current->next = prev; // Reverse the current node's pointer

            prev = current; // Move the previous pointer one step forward

            current = nextNode; // Move the current pointer one step forward

        }
        
        return prev; // At the end, prev will be the new head of the reversed list
    }
};