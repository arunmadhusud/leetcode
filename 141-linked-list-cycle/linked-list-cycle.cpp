class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // Check if the list is empty or has only one element

        ListNode* slow = head;  // Tortoise (moves one step at a time)
        ListNode* fast = head;  // Hare (moves two steps at a time)

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // Move slow pointer by one step
            fast = fast->next->next;     // Move fast pointer by two steps

            if (slow == fast) {          // If they meet, there is a cycle
                return true;
            }
        }

        return false;  // If the fast pointer reaches the end, no cycle exists
    }
};
