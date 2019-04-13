#include "stdafx.h"

int numJewelsInStones(string jewel, string stone) 
{
	map<char,int> map_stone;
	map<char,int>::iterator it;
	int result = 0;

	int len = stone.length();

	for (int n = 0; n < len; n++)
	{
		it = map_stone.find(stone.at(n));

		if (it == map_stone.end())
		{
			map_stone[stone.at(n)] = 1;
		} 
		else
		{
			it->second++;
		}
	}

	len = jewel.length();
	for (int n = 0; n < len; n++)
	{
		it = map_stone.find(jewel.at(n));

		if (it != map_stone.end())
		{
			result += it->second;
		}
	}

	return result;
}