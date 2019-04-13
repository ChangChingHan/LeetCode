#include "stdafx.h"

int findMaxConsecutiveOnes(vector<int>& nums) 
{
	int result = 0;
	int count = nums.size();
	vector<int> vlength;
 
	for (int index = 0; index < count; index++)
	{
		if (nums[index] == 0)
		{
			vlength.push_back(0);
		}
		else
		{
			if (vlength.size() ==0)
			{
				vlength.push_back(0);
			}
			vlength[vlength.size()-1] = vlength[vlength.size()-1]+1;
		}
	}

	count = vlength.size();
	for (int index = 0; index < count; index++)
	{
		if (vlength[index] > result)
		{
			result = vlength[index];
		}
	}

	return result;
}