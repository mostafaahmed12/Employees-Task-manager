#include "Employee.h"

Employee::Employee()
{
}

Employee::Employee(string userName, string password, string jobTitle)
{
	this->userName = userName;
	this->password = password;
	this->jobTitle = jobTitle;

}

void Employee::pushinqueue(Task t)
{
	pq1.push(t);

}

priority_queue<Task, vector<Task>, Priority_value_sorter> Employee::GetQueue()
{
	return pq1;
}

string Employee::GetUserName_Emp()
{
	return userName;
}

string Employee::GetEmpPass()
{
	return password;
}
string Employee::GetEmpJobT()
{
	return jobTitle;
}
void Employee::SetQueue(priority_queue<Task, vector<Task>, Priority_value_sorter> pq1)
{
	this->pq1 = pq1;
}