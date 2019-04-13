#include "stdafx.h"

int alphabet(char a)
{
	char buffer[1];
	sprintf(buffer,"%d",a);
	int i = atoi(buffer)-64;
	return i;
}

int exponential(int n)
{
	if (n == 0)
	{
		return 0;
	}
	int result = 1;
	for (int index = 0 ; index < n; index++)
	{
		result *= 26;
	}
	return result;
}

int titleToNumber(string s) 
{
	int len = s.length();
	int index = len-1;
	int r = 0;
	int exp = 0;

	for (index; index >= 0; index--)
	{
		int base = exponential(exp);
		int n = alphabet(s.at(index));
		if (base == 0)
		{
			r += n;
		}
		else
		{
			r += base*n;
		}
		
		exp++;
	}


	return r;
}