#include "stdafx.h"

//int rob(vector<int>& nums) 
//{
//	int count = nums.size();
//	int result = 0;
//	int index = 0;
//
//	vector<int> addnums;
//	vector<int> indexnums;
//
//	for (index=0; index < count; index++)
//	{
//		indexnums.push_back(index);
//	}
//
//	if(indexnums.size() == 0)
//		return 0;
//
//	while(1)
//	{
//		bool ischange = false;
//		for (index=0; index < count; index++)
//		{
//			if (index+1 < count)
//			{
//				if (nums[index+1] > nums[index])
//				{
//					ischange = true;
//					swap(nums[index+1],nums[index]);
//					swap(indexnums[index+1],indexnums[index]);
//				}
//			}
//		}
//
//		if (ischange == false)
//		{
//			break;
//		}
//	}
//
//	result = nums[0];
//	addnums.push_back(indexnums[0]);
//
//	for (index=1; index < count; index++)
//	{
//		bool can_add = false;
//		int position_index = 0;
//		int addcount = (int)addnums.size();
//
//		for (position_index; position_index < addcount; position_index++)
//		{
//			if (indexnums[index] -1 != addnums[position_index] &&
//				indexnums[index] +1 != addnums[position_index])
//			{
//				can_add = true;
//			}
//			else
//			{
//				can_add = false;
//				break;
//			}
//		}
//
//		if (can_add == true)
//		{
//			result += nums[index];
//			addnums.push_back(indexnums[index]);
//		}
//	}
//
//	int second_result = 0;
//	addnums.clear();
//
//	//if (indexnums[0] -1 == indexnums[1] ||
//	//	indexnums[0] +1 == indexnums[1])
//	if(nums.size() > 1)
//	{
//		second_result = nums[1];
//		addnums.push_back(indexnums[1]);
//
//		for (index=2; index < count; index++)
//		{
//			bool can_add = false;
//			int position_index = 0;
//			int addcount = (int)addnums.size();
//
//			for (position_index; position_index < addcount; position_index++)
//			{
//				if (indexnums[index] -1 != addnums[position_index] &&
//					indexnums[index] +1 != addnums[position_index])
//				{
//					can_add = true;
//				}
//				else
//				{
//					can_add = false;
//					break;
//				}
//			}
//
//			if (can_add == true)
//			{
//				second_result += nums[index];
//				addnums.push_back(indexnums[index]);
//			}
//		}
//	}
//
//	result = max(result,second_result);
//	return result;
//}

bool isneighbor(vector<int>& addnumsindex, int numindex)
{
	bool result = false;
	int count = addnumsindex.size();
	for (int index = 0; index < count; index++)
	{
		if (numindex+1 == addnumsindex[index] ||
			numindex-1 == addnumsindex[index])
		{
			result = true;
			break;
		}
	}
	
	return result;
}
int rob(vector<int>& nums)
{
	int count = nums.size();
	
	int result_even = 0;
	int result_odd = 0;

	vector<int> vc_even;
	vector<int> vc_odd;

	for (int index = 0; index < count; index = index+2)
	{
		result_even += nums[index];
		vc_even.push_back(index);
	}

	for (int index = 1; index < count; index = index+2)
	{
		result_odd += nums[index];
		vc_odd.push_back(index);
	}

	int result = max(result_odd,result_even);
//=================================================

	int cross_even = 0;
	int cross_odd = 0;
	vector<int> addnumsindex;

	if (vc_even.size()>0 && vc_odd.size()>0)
	{
		count = vc_even.size();
		int odd_index = vc_odd.size()-1;
		for (int index = 0; index < count; index++)
		{
			if (isneighbor(addnumsindex,vc_even[index]) == false)
			{
				cross_even += nums[vc_even[index]];
				addnumsindex.push_back(vc_even[index]);
			}
			else
			{
				break;
			}

			if (isneighbor(addnumsindex,vc_odd[odd_index]) == false)
			{
				cross_even += nums[vc_odd[odd_index]];
				addnumsindex.push_back(vc_odd[odd_index]);
			}
			else
			{
				break;
			}
			odd_index--;
		}
	}

	count = vc_odd.size();
	int even_index = vc_even.size()-1;
	addnumsindex.clear();

	if (vc_even.size()>0 && vc_odd.size()>0)
	{
		for (int index = 0; index < count; index++)
		{
			if (isneighbor(addnumsindex,vc_odd[index]) == false)
			{
				cross_odd += nums[vc_odd[index]];
				addnumsindex.push_back(vc_odd[index]);
			}
			else
			{
				break;
			}

			if (isneighbor(addnumsindex,vc_even[even_index]) == false)
			{
				cross_odd += nums[vc_even[even_index]];
				addnumsindex.push_back(vc_even[even_index]);
			}
			else
			{
				break;
			}
			
			even_index--;
		}
	}
	

	int cross = max(cross_odd,cross_even);

	result = max(result,cross);
	return result;
}