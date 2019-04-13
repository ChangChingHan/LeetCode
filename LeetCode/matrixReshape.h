#include "stdafx.h"

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
{
	vector<vector<int>> matrix;

	int matrixcount = 0;
	int count = r*c;
	int row = nums.size();
	vector<int> plate;

	for (int index = 0; index < row; index++)
	{
		int c_count = nums[index].size();
		matrixcount += c_count;
		
		for (int cindex = 0; cindex < c_count; cindex++)
		{
			plate.push_back(nums[index][cindex]);
		}
	}

	if (matrixcount == count)
	{
		int p_index = 0;
		for (int rindex = 0; rindex < r; rindex++)
		{
			vector<int> collumn;
			matrix.push_back(collumn);
			for (int cindex = 0; cindex < c; cindex++)
			{
				matrix[rindex].push_back(plate[p_index++]);
			}
		}
	}
	else
	{
		matrix = nums;
	}

	return matrix;
}