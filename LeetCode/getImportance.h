#include "stdafx.h"

class Employee 
{
	public:
		int id;
		int importance;
		vector<int> subordinates;
};

vector<Employee*> prepareEmployeeData()
{
	vector<Employee*> list;
	vector<int> listid;
	listid.push_back(2);
	listid.push_back(3);

	Employee *e = new Employee();
	e->id = 1;
	e->importance = 5;
	e->subordinates = listid;
	list.push_back(e);

	Employee *e2 = new Employee();
	listid.clear();
	e2->id = 2;
	e2->importance = 3;
	e2->subordinates = listid;
	list.push_back(e2);

	Employee *e3 = new Employee();
	e3->id = 3;
	e3->importance = 3;
	e3->subordinates = listid;
	list.push_back(e3);

	return list;
}

int getImportance(vector<Employee*> employees, int id) 
{
	int score = 0;
	int count = employees.size();

	for (int i = 0; i < count; i++)
	{
		if ( employees[i]->id == id)
		{
			int subordinateCount = employees[i]->subordinates.size();
			if (subordinateCount > 0)
			{
				for (int j = 0; j < subordinateCount; j++)
				{
					score += getImportance(employees, employees[i]->subordinates[j]);
				}
			} 
			else
			{
				return employees[i]->importance;
			}
			score += employees[i]->importance;
			break;
		}
	}

	return score; 
}