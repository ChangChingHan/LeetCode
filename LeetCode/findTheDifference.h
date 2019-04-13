#include "stdafx.h"
#https://leetcode.com/problems/find-the-difference/

char findTheDifference(string s, string t) 
{
	char c = ' ';
	int count_s = s.length();
	int count_t = t.length();

	for (int index_s = 0; index_s < count_s; index_s++)
	{
		count_t = t.length();
		
		for (int index_t = 0; index_t < count_t; index_t++)
		{
			if (s.at(index_s) == t.at(index_t))
			{
				t.erase(t.begin()+index_t);
				break;
			}
		}
	}

	c = t.at(0);
	return c;
}
