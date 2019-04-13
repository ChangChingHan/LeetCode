#include "stdafx.h"

int tow_pow(int n)
{
	int tow = 1;

	for (int index = 0; index < n; index++)
	{
		tow *= 2;
	}
	return tow;
}

int findComplement(int num)
{
	int result = 0;
	int integer = 1;
	int shiftinteger = 0;
	int high_position = 0;
	
	for (int index = 0; index < 32; index++)
	{
		shiftinteger = integer << index;

		if (shiftinteger & num)
		{
			high_position = index;
		}
	}

	shiftinteger = integer << high_position;

	for (int index = 0; index <= high_position; index++)
	{
		shiftinteger = integer << index;

		if (!(shiftinteger & num))
		{
			result += tow_pow(index);
		}
	}

	return result;
}

