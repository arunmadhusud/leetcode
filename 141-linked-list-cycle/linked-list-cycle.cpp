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
        if (head==nullptr) return false;
        unordered_set<ListNode*> visited;
        visited.insert(head);
        ListNode* curr = head->next;
        while (curr!=nullptr){
            if(visited.find(curr) != visited.end()) return true;
            else visited.insert(curr);
            curr = curr->next;

        }
        return false;
        
    }
};