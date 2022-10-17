#include "Task.h"

Task::Task(string id, string task_name, string task_description, string assigned_date, string due_date, int priority_value)
{
	this->id = id;
	this->assigned_date = assigned_date;
	this->task_description = task_description;
	this->task_name = task_name;
	this->due_date = due_date;
	this->priority_value = priority_value;

}

Task::Task()
{
}

void Task::SetId(string id)
{
	this->id = id;
}

void Task::SetTaskName(string name)
{
	this->task_name = name;
}

void Task::SetPriorityValue(int p)
{
	this->priority_value = p;
}

void Task::SetDes(string des)
{
	this->task_description = des;
}

void Task::setAssignDate(string assdate)
{
	this->assigned_date = assdate;
}

void Task::SetDueDate(string duedate)
{
	this->due_date = duedate;
}

int Task::getPriority_value()
{
	return priority_value;
}

string Task::getid()
{
	return id;
}

string Task::get_task_name()
{
	return task_name;
}

