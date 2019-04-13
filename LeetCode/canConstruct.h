#include "stdafx.h"

bool canConstruct(string ransomNote, string magazine) 
{
	if (ransomNote.compare(magazine) == 0)
	{
		return true;
	}
	bool result = false;
	int count = magazine.length();
	int len = ransomNote.length();
	bool deletechar = false;


	while(1)
	{
		deletechar = false;
		count = magazine.length();
		len = ransomNote.length();

		for (int indexr = 0; indexr < len; indexr++)
		{
			for (int indexm = 0; indexm < count; indexm++)
			{
				if (ransomNote.at(indexr) == magazine.at(indexm))
				{
					deletechar = true;
					ransomNote.erase(ransomNote.begin()+indexr);
					magazine.erase(magazine.begin()+indexm);
					break;
				}
			}
			if (deletechar == true)
				break;
		}

		if (deletechar == false)
			break;
	}
	
	result = ransomNote.length()>0?false:true;
	
	return result;
}