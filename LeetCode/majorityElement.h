#include "stdafx.h"

int majorityElement(vector<int>& nums) 
{
	map<int,int> m;
	int count = nums.size();
	map<int,int>::iterator it;

	for (int index = 0; index < count; index++)
	{
		it = m.find(nums[index]); 

		if (it == m.end())
		{
			m[nums[index]] = 1;
		}
		else
		{
			it->second++;
		}
	}

	it = m.begin();
	int result = 0;
	int times = 0;
	while(it != m.end())
	{
		if (it->second > times)
		{
			result = it->first;
			times = it->second;
		}
		it++;
	}

	return result;
}