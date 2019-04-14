# https://leetcode.com/problems/add-two-numbers
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
    
    ListNode* addNumbers(ListNode* l1, ListNode* l2, 
                            int carry, ListNode* result) {
        if (l1 == NULL && l2 == NULL) {
            if (carry > 0) {
                result->next = new ListNode(carry);
                return result;
            } else return NULL;
        } else {
            int x,y = 0;
            ListNode*pl1,*pl2;
            
            if (l1 == NULL && l2 != NULL)
            {x = 0; y = l2->val; pl1 = NULL; pl2 = l2->next;} 
            else if (l1 != NULL && l2 == NULL)
            {x = l1->val; y = 0; pl1 = l1->next; pl2 = NULL;}
            else
            {x = l1->val; y = l2->val; pl1 = l1->next; pl2 = l2->next;}
            
            int n = x + y + carry;
            carry = n / 10;
            result->next = new ListNode(n % 10);
            //std:cout << result->next->val;
            return addNumbers(pl1, pl2, carry, result->next);
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        
        if(l1 != NULL && l2 != NULL) {
            int n = l1->val + l2->val;
            int carry = n / 10;
            result = new ListNode(n % 10);
            addNumbers(l1->next, l2->next, carry, result);
        }
        return result;
    }
};
