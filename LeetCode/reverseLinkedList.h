# https://leetcode.com/problems/reverse-linked-list/
#include "stdafx.h"

struct linkedlist
{
	int val;
	linkedlist *next;
	linkedlist(int x) : val(x), next(NULL){}
};

linkedlist* prepareData()
{
	linkedlist *p = new linkedlist(0);
	p->next = new linkedlist(1);
	p->next->next = new linkedlist(2);
	p->next->next->next = new linkedlist(3);
	p->next->next->next->next = new linkedlist(4);
	p->next->next->next->next->next = new linkedlist(5);

	return p;
}

void revers()
{
	linkedlist* p = prepareData();

	linkedlist *f = p;
	linkedlist *n = NULL;

	while(f != NULL)
	{
		if (f->next == NULL)
		{
			f->next = n;
			break;
		}

		linkedlist * t = f->next;
		f->next = n;
		n = f;
		f = t;
	}

	p = f;

}

void reverseLinkedList()
{
	linkedlist* p = prepareData();

	linkedlist *b = NULL;
	linkedlist *f = p;

	while(f != NULL)
	{
		if(f->next != NULL)
		{
			linkedlist *t = f->next;
			f->next = b;
			b = f;
			f = t;
		}
		else
		{
			f->next = b;
			break;
		}
	}

	p = f;
}

/*recursive solution*/
class Solution {
public:
    ListNode* reverse(ListNode* p, ListNode* q) {
        if(q == NULL) return NULL;
        else 
        {
            ListNode* nxp = q;
            ListNode* nxq = q->next;
            q->next = p;
            
            if (nxq == NULL) {
                return nxp;
            } else
                return reverse(nxp,nxq);
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* result;
        if (head != NULL) {
            return reverse(NULL,head);
        } else {
            return NULL;
        }
    }
};
