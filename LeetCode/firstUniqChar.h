#include "stdafx.h"

int firstUniqChar(string s) 
{
	vector<pair<char,int>> v;
	int count = s.length();

	for (int index = 0; index < count; index++)
	{
		pair<char,int> p;
		v.push_back(p);

		int char_count = v.size();
		bool found = false;
		for (int i = 0; i < char_count; i++)
		{
			if (s.at(index) == v[i].first)
			{
				found = true;
				v[i].second = 0;
				break;
			}
		}

		if (found == false)
		{
			v[index].first = s.at(index);
			v[index].second = 1;
		}
	}


	for (int index = 0; index < count; index++)
	{
		if (v[index].second == 1)
		{
			return index;
		}
	}
	return -1;
}