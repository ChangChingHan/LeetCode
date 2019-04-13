#include "stdafx.h"

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{
	vector<string> v;
	int length = 0;

	int count1 = list1.size();
	int count2 = list2.size();

	for (int index1 = 0; index1 < count1; index1++)
	{
		for (int index2 = 0; index2 < count2; index2++)
		{
			if ( list1[index1].compare(list2[index2]) == 0)
			{
				if(length == 0 && v.size() == 0)
				{
					length = index1+index2;
					v.push_back(list1[index1]);
				}
				else
				{
					if (index1+index2 < length)
					{
						v.clear();
						v.push_back(list1[index1]);
						length = index1+index2;
					}
					else if (index1+index2 == length)
					{
						v.push_back(list1[index1]);
					}
				}
			}
		}
	}

	return v;
}