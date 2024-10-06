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
    bool hasCycle(ListNode *head) {
        ListNode* slwptr = head;
        ListNode* fstptr = head;
        while(fstptr!=nullptr && fstptr->next!=nullptr){
            slwptr = slwptr->next;
            fstptr = fstptr->next->next;
            if(fstptr==nullptr) return false;
            if(fstptr==slwptr) return true;
        }
        return false;        
    }
};