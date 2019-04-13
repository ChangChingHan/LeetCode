#include "stdafx.h"

void sort(vector<int>& nums,int m)
{
	if (m < nums.size())
	{
		int i = nums.size()-1;
		while(nums.begin()+i != nums.begin())
		{
			if (m == nums.size())
				break;

			if ((nums[i]) == 0)
			{
				nums.erase(nums.begin()+i);
				i--;
				continue;
			}
		}
	}
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	if (n == 0)
	{
		return;
	}

	if (m == 0)
	{
		nums1 = nums2;
		return;
	}

	if(nums2[0] > nums1[m-1])
	{
		nums1.insert(nums1.begin()+m-1, nums2[0]);
		nums2.erase(nums2.begin());
		if (nums2.size() == 0)
		{
			return;
		}
		else
			merge(nums1,nums1.size(),nums2,nums2.size());
	}

	bool b = false;
	for(int index = 0; index < m; index++)
	{
		for(int j = 0; j< n; j++)
		{
			if(nums2[j] < nums1[index])
			{
				nums1.insert(nums1.begin()+index, nums2[j]);
				nums2.erase(nums2.begin()+j);
				b = true;
				break;
			}
		}
		if (b==true)
		{
			break;
		}
	}

	if (nums2.size() == 0)
	{
		return;
	}
	else
		merge(nums1,nums1.size(),nums2,nums2.size());
}
