#include "stdafx.h"

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> vresult;
	map<int,int> mresult;
	map<int,int>::iterator it;


	int count1 = nums1.size();
	int count2 = nums2.size();
	

	for (int index1 = 0; index1 < count1; index1++)
	{
		for (int index2 = 0; index2 < count2; index2++)
		{
			if (nums1[index1] == nums2[index2])
			{
				it = mresult.find(nums1[index1]);
				if (it == mresult.end())
				{
					mresult[nums1[index1]] = 0;
					vresult.push_back(nums1[index1]);
				}
			}
		}
	}

	return vresult;
}