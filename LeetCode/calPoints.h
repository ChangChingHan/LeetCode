#include "stdafx.h"

vector<string> createcalPoints()
{
	//["5","-2","4","C","D","9","+","+"]
	vector<string> ops;
	ops.push_back("5");
	ops.push_back("-2");
	ops.push_back("4");
	ops.push_back("C");
	ops.push_back("D");
	ops.push_back("9");
	ops.push_back("+");
	ops.push_back("+");

	return ops;
}

int calPoints(vector<string>& ops) 
{
	int result = 0;
	int count = ops.size();
	vector<int> score;

	for (int i = 0 ; i < ops.size(); i++)
	{
		if (ops[i].compare("C") == 0)
		{
			result -= score[score.size()-1];
			score.pop_back();
		}
		else if (ops[i].compare("D") == 0)
		{
			int d = 2*score[score.size()-1];
			result += d;
			score.push_back(d);
		}
		else if (ops[i].compare("+") == 0)
		{
			int p = score[score.size()-1] + score[score.size()-2];
			result += p;
			score.push_back(p);
		}
		else
		{
			score.push_back(atoi(ops[i].c_str()));
			result += atoi(ops[i].c_str());
		}
	}

	return result;
}
