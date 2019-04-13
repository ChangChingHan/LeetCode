#include "stdafx.h"

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
{
	vector<int> result;
	int findcount = findNums.size();

	for (int find_index = 0; find_index < findcount; find_index++)
	{
		bool equal_on = false;
		bool add = false;

		int num_count = nums.size();
		for(int num_index = 0; num_index < num_count; num_index++)
		{
			if (equal_on == true)
			{
				if (nums[num_index] > findNums[find_index])
				{
					result.push_back(nums[num_index]);
					add = true;
					break;
				}
			}
			else
			{
				if (nums[num_index] == findNums[find_index])
				{
					equal_on = true;
				}
			}
		}

		if (add == false)
		{
			result.push_back(-1);
		}
	}

	return result;
}