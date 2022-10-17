#pragma once
#include <string>
using namespace std;
class Task
{
public:
	string id;
	string task_description;
	string assigned_date;
	string due_date;
public:
	int priority_value;
	string task_name;
	string getid();
	string get_task_name();
	int getPriority_value();
	Task(string id, string task_name, string task_description, string assigned_date, string due_date, int priority_value);
	Task();
	void SetId(string id);
	void SetTaskName(string name);
	void SetPriorityValue(int p);
	void SetDes(string des);
	void setAssignDate(string assdate);
	void SetDueDate(string duedate);

	bool operator()(Task const& p1, Task const& p2) {

		return p1.priority_value < p2.priority_value;
	}
};
