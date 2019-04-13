#include "stdafx.h"

bool detectCapitalUse() 
{
	string word = "cVe";

	char buffer[128];

	sprintf(buffer,"%s",word.c_str());
	int count = strlen(buffer);

	if (count <= 2)
	{
		if(count == 1)
			return true;
		else
		{
			if(isupper((buffer[0])) == 0 && isupper((buffer[1])) != 0)
				return false;
		}
	}
	else
	{
		if(isupper((buffer[0])) == 0 && isupper((buffer[1])) != 0)
			return false;

		bool upper = false;
		if (isupper((buffer[0])) != 0 && isupper((buffer[1])) != 0)
			upper = true;

		for (int i=2; i< count; i++)
		{                
			if (upper == true)
			{
				if (isupper(buffer[i]) == 0)
				{
					return false;
				}
			} 
			else
			{
				if (isupper(buffer[i]) != 0)
				{
					return false;
				}
			}
		}
	}

	return true; 
}