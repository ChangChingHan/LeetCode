#include "stdafx.h"

bool containsDuplicate(vector<int>& nums) 
{
	int count = nums.size();

	for (int index = 0; index < count; index++)
	{
		for (int d_index = 0; d_index < count; d_index++)
		{
			if (d_index != index)
			{
				if (nums[index] == nums[d_index])
				{
					return true;
				}
			}
		}

	}

	return false;
}