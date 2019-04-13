#include "stdafx.h"

vector<pair<int,int>> sort(vector<int> nums)
{
	vector<pair<int,int>> sortnums;

	int count = nums.size();

	for (int index = 0; index < count; index++)
	{
		pair<int,int> p;
		p.first = nums[index];
		p.second = index;
		sortnums.push_back(p);
	}

	while(1)
	{
		bool isswap = false;

		for (int index = 1; index < count; index++)
		{
			if (sortnums[index].first > sortnums[index-1].first)
			{
				isswap = true;
				swap(sortnums[index],sortnums[index-1]);
			}
		}

		if (isswap == false)
		{
			break;
		}
	}

	return sortnums;
}


vector<string> findRelativeRanks(vector<int>& nums) 
{
	vector<pair<int,int>> sortnums = sort(nums);
	vector<string> v;

	int count = nums.size();
	v.resize(count,"");
	
	for (int index = 0; index < count; index++)
	{
		sortnums[index];

		if (index == 0)
		{
			v[sortnums[index].second] = "Gold Medal";
		}
		else if (index == 1)
		{
			v[sortnums[index].second] = "Silver Medal";
		}
		else if (index == 2)
		{
			v[sortnums[index].second] = "Bronze Medal";
		}
		else
		{
			char buffer[5];
			sprintf(buffer,"%d",index+1);
			v[sortnums[index].second] = buffer;
		}	 
	}

	return v;
}