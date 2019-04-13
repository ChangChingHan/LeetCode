#include "stdafx.h"

struct linkedlist
{
	int val;
	linkedlist * next;

	linkedlist(int x):val(x),next(NULL){}
};

linkedlist* create()
{
	linkedlist *p = new linkedlist(0);
	p->next = new linkedlist(1);
	p->next->next = new linkedlist(2);
	p->next->next->next = new linkedlist(3);
	p->next->next->next->next = new linkedlist(4);

	return p;
}

linkedlist* clone(linkedlist *r)
{
	return r;
}

linkedlist* deletenode(linkedlist *d, linkedlist *r)
{
	if(d == NULL)
		return r;
	if (r == NULL)
		return r;
	

	linkedlist *f = r;

	if (f->val == d->val)
	{
		r = r->next;
		delete f;
		return r;
	}
	
	while(f != NULL)
	{
		if(f->next == NULL)
			break;
		
		if(f->next->val == d->val)
		{
			linkedlist *t = f->next->next;
			linkedlist *n = f->next;
			f->next = t;
			delete n;
			break;
		}
		
		f = f->next;
	}

	return r;
}

