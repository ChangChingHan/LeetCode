#include "stdafx.h"

int removeElement(vector<int>& nums, int val)
{
	int result = 0;
	int count = nums.size();
	int index = 0;
	vector<int>::iterator it = nums.begin();
	for (index = 0; index < count; index++)
	{
		if (nums[index] == val)
		{
			nums.erase(it+index);
			index--;
			count = nums.size();
			it = nums.begin();
		}
	}
	result = nums.size();
	return result;
}