#include "stdafx.h"

bool isAnagram(string s, string t) 
{
	if (s.length() != t.length())
	{
		return false;
	}

	int count = s.length();

	for (int index = 0; index < count; index++)
	{
		int t_count = t.length();

		for (int t_index = 0; t_index < t_count; t_index++)
		{
			if (s.at(index) == t.at(t_index))
			{
				t.erase(t.begin()+t_index);
				break;
			}
		}
	}

	if (t.length() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}