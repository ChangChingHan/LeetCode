#include "stdafx.h"

int singleNumber(vector<int>& nums) 
{
	int count = nums.size();
	map<int, int> checkmap;
	map<int, int>::iterator it;

	for (int index = 0; index < count; index++)
	{
		it = checkmap.find(nums[index]);
		if (it == checkmap.end())
		{
			checkmap[nums[index]] = 1;
		}
		else
		{
			checkmap.erase(it);
		}
	}
	it = checkmap.begin();

	if (it != checkmap.end())
	{
		return it->first;
	}
	else
		return 0;
	
}