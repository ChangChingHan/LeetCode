#include "stdafx.h"

vector<vector<int>> createisToeplitzMatrix()
{
	vector<vector<int>> matrix;

	return matrix;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) 
{
	if (matrix.size() == 0)
		return true;
	
	int row = matrix.size();
	int col = matrix[0].size();

	int diagonal = row + col -1;
	
	for (int i = 0; i < diagonal; i++)
	{
		
	}
}