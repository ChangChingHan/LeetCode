# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;
        
        if (head->val == head->next->val) {
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            head = head->next;
            return deleteDuplicates(head);
        }
        
        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        
        return head;
    }
};
