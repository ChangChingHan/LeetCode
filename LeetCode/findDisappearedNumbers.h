#include "stdafx.h"


vector<int> findDisappearedNumbers(vector<int>& nums) 
{
	int count = nums.size();
	vector<int> a;
	a.assign(count,0);
	vector<int> result;

	for (int index = 0; index < count; index++)
	{
		a[nums[index]-1] = 1;
	}

	for (int index = 0; index < count; index++)
	{
		if (a[index] == 0)
		{
			result.push_back(index+1);
		}
	}

	return result;
}