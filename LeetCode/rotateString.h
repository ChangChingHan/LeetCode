#include "stdafx.h"

bool rotateString(string A, string B) 
{
	bool isSame = true;

	if (A.length() != B.length())
	{
		return false;
	}

	map<int,char> strA;
	
	for (int n = 0; n < A.length(); n++)
	{
		if (A.at(n) == B.at(0))
		{
			strA[n] = A.at(n);
		}
	}

	map<int,char>::iterator it = strA.begin();
	if(it == strA.end())
		return false;

	while(it != strA.end())
	{
		isSame = true;
		int j = it->first;

		for (int i = 0; i < B.length(); i++)
		{
			if (j >= B.length())
			{
				j = 0;
			}

			if (A.at(j) != B.at(i))
			{
				isSame = false;
				break;
			}
			j++;
		}

		if (isSame == true)
		{
			return true;
		}
		it++;
	}

	return isSame;
}