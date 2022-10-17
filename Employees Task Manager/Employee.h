#pragma once
#include<string>
#include<iostream>
#include<queue>
#include"Task.h"
struct Priority_value_sorter {
	bool operator()(const Task& lhs, const Task& rhs)
	{
		return lhs.priority_value < rhs.priority_value;
	}
};
class Employee
{
private:
	string userName;
	string password;
	string jobTitle;
	priority_queue<Task, vector<Task>, Priority_value_sorter>pq1;

public:
	Employee();
	Employee(string userName, string passwrod, string jobTitle);
	void pushinqueue(Task t);

	string GetUserName_Emp();
	string GetEmpPass();
	string GetEmpJobT();
	priority_queue<Task, vector<Task>, Priority_value_sorter>GetQueue();

	void SetQueue(priority_queue<Task, vector<Task>, Priority_value_sorter>pq1);

};
