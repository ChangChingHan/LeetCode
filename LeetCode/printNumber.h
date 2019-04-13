#include "stdafx.h"


void recursice(string& str, bool add, int& n, int t)
{
	if (add == true)
	{
		if (n < t)
		{
			n = n+5;
			char buffer[8];
			itoa(n,buffer,10);
			str += buffer;
			recursice(str,add,n,t);
		}
		else
			return;
	}
	else
	{
		if (n > 0)
		{
			n = n-5;
			char buffer[8];
			itoa(n,buffer,10);
			str += buffer;
			recursice(str,add,n,t);
		}
		else
			return;
	}
}


void printNumber()
{
	int n = 11;
	int t = 11;
	string result = "11";

	recursice(result,false,n,t);
	recursice(result,true,n,t);
}