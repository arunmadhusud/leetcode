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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for(int i = 0; i < left - 1; i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* prevNode = prev;
        ListNode* leftNode = curr;

        ListNode* tmp = nullptr;
        for(int k = 0; k <= right- left; k++){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        if(prevNode!=nullptr) prevNode->next = prev;
        else head = prev;
        leftNode->next = curr;
        return head;
    }

};
