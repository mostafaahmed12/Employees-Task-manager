#pragma once
#include <iostream>
#include "Employee.h"
#include "Task.h"
#include "Admin.h"
#include <unordered_map>

using namespace std;
class SSystem
{
private:

public:
	SSystem();
	string CurrentId;
	unordered_map<string, Employee>mapOfEmployees;
	unordered_map<string, Admin>mapOfAdmins;
	vector<Task>vectorOfTasks;
	priority_queue<Task, vector<Task>, Priority_value_sorter>AllTasks;
	void PushTaskInSystem(Task t);
	void ViewAllTasksInSystem();
	void ViewAllUsersInSystem();
	void open();
	void adminmenu();
	void empmenu();
	void AddNewTask();
	void EmpTasks();
	void CompleteTask();
	void EditTask();
	void Reminder();
};