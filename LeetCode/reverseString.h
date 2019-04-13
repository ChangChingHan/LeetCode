#include "stdafx.h"


string reverseString(string s) 
{
	string result = "";
	int count = s.length();

	for (int index = count-1; index >= 0; index--)
	{
		result += s.at(index);
	}

	return result;
}