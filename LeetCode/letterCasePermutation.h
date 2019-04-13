#include "stdafx.h"

vector<string> letterCasePermutation(string s) 
{
	vector<string> result;
	vector<int> alphabet_position;

	result.push_back(s);
	for (int i = 0 ; i < s.length(); i++)
	{
		if (s.at(i) >= 0x41)
		{
			alphabet_position.push_back(i);
		}
	}

	if(alphabet_position.size() == 0)
		return result;
	else
	{
		int c = alphabet_position.size();

		for (int i = 0; i < c; i ++)
		{
			tolower(s.at(i))
			//toupper()
		}
	}
}