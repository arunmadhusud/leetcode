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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Move to the node at position `left`
        for(int i = 0; i < left - 1; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Mark the nodes at the start and before the start of the reverse sublist
        ListNode* beforeLeft = prev;
        ListNode* leftNode = curr;

        // Reverse the sublist between `left` and `right`
        ListNode* tmp = nullptr;
        for (int i = 0; i <= right - left; i++) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // Reconnect the reversed sublist with the rest of the list
        if (beforeLeft != nullptr) {
            beforeLeft->next = prev;
        } else {
            head = prev;  // Update head if reversing starts at position 1
        }
        leftNode->next = curr;

        return head;
    }
};
