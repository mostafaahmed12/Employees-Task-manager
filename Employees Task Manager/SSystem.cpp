#include "SSystem.h"
#include <Windows.h>
#include <fstream>
#include <conio.h>

SSystem::SSystem()
{
	Admin a1("admin", "admin");

	mapOfAdmins[a1.GetUserName_Admin()] = a1;

	Employee e1("mostafa", "2222", "HR");
	Employee e2("abdelrahman", "3333", "PR");
	Employee e3("moataz", "4444", "Manager");

	mapOfEmployees[e1.GetUserName_Emp()] = e1;
	mapOfEmployees[e2.GetUserName_Emp()] = e2;
	mapOfEmployees[e3.GetUserName_Emp()] = e3;

	Task t1("mostafa", "Interview", "Interview with Adel", "1/6", "3/6", 8);
	Task t2("abdelrahman", "Interview", "Interview with Lily", "2/6", "4/6", 8);
	Task t3("abdelrahman", "Meeting", "Meeting about new salaries", "30/5", "1/6", 10);
	Task t4("moataz", "Meeting", "Meeting to increase employees salaries", "30/5", "1/6", 10);
	Task t5("moataz", "Salary", "Calculate Salary Increase", "25/5", "29/5", 9);
	Task t6("moataz", "Arrange Meeting", "Select The Meeting Date", "29/5", "30/5", 7);

	AllTasks.push(t1);
	AllTasks.push(t2);
	AllTasks.push(t3);
	AllTasks.push(t4);
	AllTasks.push(t5);
	AllTasks.push(t6);

	vectorOfTasks.push_back(t1);
	vectorOfTasks.push_back(t2);
	vectorOfTasks.push_back(t3);
	vectorOfTasks.push_back(t4);
	vectorOfTasks.push_back(t5);
	vectorOfTasks.push_back(t6);

	mapOfEmployees[t1.getid()].pushinqueue(t1);
	mapOfEmployees[t2.getid()].pushinqueue(t2);
	mapOfEmployees[t3.getid()].pushinqueue(t3);
	mapOfEmployees[t4.getid()].pushinqueue(t4);
	mapOfEmployees[t5.getid()].pushinqueue(t5);
	mapOfEmployees[t6.getid()].pushinqueue(t6);

	open();
}
void SSystem::PushTaskInSystem(Task t)
{
	this->AllTasks.push(t);
}
void SSystem::ViewAllTasksInSystem()
{
	priority_queue<Task, vector<Task>, Priority_value_sorter>a = this->AllTasks;
	system("cls");
	int counter = 1;
	bool x = true;
	cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>         Employees Tasks        <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------\n\n" << endl;
	while (!a.empty())
	{
		x = false;
		cout << counter << ".Employee Name: " << a.top().id << " , Task Name: " << a.top().task_name << " , Task Description: " << a.top().task_description << endl <<
			"Assigning Date: " << a.top().assigned_date << " , End Date: " << a.top().due_date << " , Priority Value: " << a.top().priority_value << ".\n\n";
		a.pop();
		counter++;
	}
	if (x)
	{
		cout << "\t\t\t\t<:No Tasks, Employees Finished All Of Their Tasks :>";
	}
	cout << "\t\t\t\t\t ------------------------------------\n";
	system("PAUSE");
	adminmenu();
}
void SSystem::ViewAllUsersInSystem()
{
	int counter = 1;
	system("cls");
	cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>       All Employee's Data:     <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	for (auto i : mapOfEmployees)
	{
		cout << "\t\t\t\t\t  " << counter << ".Employee's Name : " << i.first << "\n\t\t\t\t\t" << "  Employee's Job : " << mapOfEmployees[i.first].GetEmpJobT() << "\n\n";
		counter++;
	}
	cout << "\t\t\t\t\t ------------------------------------\n";
	system("PAUSE");
	adminmenu();

}
void SSystem::Reminder()
{
	bool x = true;
	priority_queue<Task, vector<Task>, Priority_value_sorter>a = this->AllTasks;
	while (!a.empty())
	{
		if (a.top().id == CurrentId)
		{
			cout << a.top().task_name << "\n";
			x = false;
			break;
		}
		a.pop();
	}
	if (x == true)
	{
		cout << "No Task.\n";
	}
}
void SSystem::AddNewTask()
{
	string id, task_name, task_description, assigned_date, due_date;
	int priority_value;
	system("cls");
	cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>         Add A New Task:        <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	cout << "\n\t\t\t\t\t Enter Employee's Name: ";
	cin >> id;
	if (mapOfEmployees.find(id) != mapOfEmployees.end())
	{
		cout << "\n\t\t\t\t\t Enter Task Name: "; cin.ignore(); getline(cin, task_name);
		cout << "\n\t\t\t\t\t Enter Task Description: "; getline(cin, task_description);
		cout << "\n\t\t\t\t\t Enter Assigning Date: "; cin >> assigned_date;
		cout << "\n\t\t\t\t\t Enter End Date: "; cin >> due_date;
		cout << "\n\t\t\t\t\t Enter Priority Value (From 1 to 10): "; cin >> priority_value;
		
		while (!cin.good()) // validation  input should be integer
		{
			cout << "\n\t\t\t\t\t Error: Please Enter Integer Number!";
			cin.clear(); //clear cin
			cin.ignore(INT_MAX, '\n');//then ignore data
			cout << "\n\t\t\t\t\t Enter Priority Value (From 1 to 10): ";
			cin >> priority_value;//then get  input Again
			while (priority_value < 1 || priority_value > 10)
			{
				cout << "\n\t\t\t\t\t Error: Please Enter Value From 1 To 10: ";
				cin >> priority_value;
			}
		}
		while (priority_value < 1 || priority_value > 10) 
		{
			cout << "\n\t\t\t\t\t Error: Please Enter Value From 1 To 10: ";
			cin >> priority_value;
			while (!cin.good()) // validation  input should be integer
			{
				cout << "\n\t\t\t\t\t Error: Please Enter Integer Number!";
				cin.clear(); //clear cin
				cin.ignore(INT_MAX, '\n');//then ignore data
				cout << "\n\t\t\t\t\t Enter Priority Value (From 1 to 10): ";
				cin >> priority_value;//then get  input Again
				while (priority_value < 1 || priority_value > 10)
				{
					cout << "\n\t\t\t\t\t Error: Please Enter Value From 1 To 10: ";
					cin >> priority_value;
				}
			}
		}
		Task t(id, task_name, task_description, assigned_date, due_date, priority_value);
		mapOfEmployees[id].pushinqueue(t);
		AllTasks.push(t);
		vectorOfTasks.push_back(t);
		cout << "\n\n\t\t\t\t\t     Task Added Successfully!";
		cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	}
	else
	{
		cout << "\n\n\t\t\t\t\t There Is No Employee With This Name.";
		cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	}
	system("PAUSE");
	adminmenu();
}
void SSystem::EmpTasks()
{
	bool x = true;
	int counter = 1;
	priority_queue<Task, vector<Task>, Priority_value_sorter>a = this->AllTasks;
	system("cls");
	cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>            Your Tasks          <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	while (!a.empty())
	{
		if (a.top().id == CurrentId)
		{
			x = false;
			cout << "\n\t\t" << counter << ".Task Name: " << a.top().task_name << " , Task Description: " << a.top().task_description << endl;
			cout << "\t\tAssigning Date: " << a.top().assigned_date << " , End Date: " << a.top().due_date << " , Priority Value: " << a.top().priority_value << ".\n";
			counter++;
		}
		a.pop();
	}
	if (x == true)
	{
		cout << "\t\t\t\t\t\t    No Current Tasks.\n\n\t\t\t<: Good job u've finished all your tasks, Keep Up The Good Work! :>\n";
	}
	cout << "\t\t\t\t\t ------------------------------------\n";
	system("PAUSE");
	empmenu();
}
void SSystem::CompleteTask()
{
	system("cls");
	string TName;
	string EName;
	priority_queue<Task, vector<Task>, Priority_value_sorter>a = this->AllTasks;
	cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>          Complete Task         <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	if (CurrentId == "admin")
	{
		cout << "\n\t\t\t\t\t Enter Employee Name: ";
		cin >> EName;
	}
	else
	{
		EName = CurrentId;
	}
	if (mapOfEmployees.find(EName) != mapOfEmployees.end())
	{
		cout << "\n\t\t\t\t\t Write The Task Name To Complete It: ";
		cin.ignore();
		getline(cin, TName);
		priority_queue<Task, vector<Task>, Priority_value_sorter>q = mapOfEmployees[EName].GetQueue();
		priority_queue<Task, vector<Task>, Priority_value_sorter>newqueue;
		bool flag = false;
		while (!q.empty())
		{
			if (q.top().task_name == TName)
			{
				cout << "\n\t\t\t\t\t Task Completed.\n";
				cout << "\t\t\t\t\t ------------------------------------" << endl;
				flag = true;
			}
			else
			{
				newqueue.push(q.top());
			}
			q.pop();
		}
		if (flag) {
			mapOfEmployees[EName].SetQueue(newqueue);
			priority_queue<Task, vector<Task>, Priority_value_sorter>qsystem;
			while (!AllTasks.empty())
			{
				if (AllTasks.top().id == EName && AllTasks.top().task_name == TName)
				{
				}
				else
				{
					qsystem.push(AllTasks.top());
				}
				AllTasks.pop();
			}
			AllTasks = qsystem;
			vector<Task>v;
			for (auto i : vectorOfTasks)
			{
				if (i.id == EName && i.task_name == TName)
				{
				}
				else
				{
					v.push_back(i);
				}
			}
			vectorOfTasks = v;
		}
		else
		{
			cout << "\n\t\t\t\t\t No Task With This Name.\n";
			cout << "\t\t\t\t\t ------------------------------------" << endl;
		}
	}
	else
	{
		cout << "\n\t\t\t\t\t No Employee Named '" << EName << "'.\n";
		cout << "\t\t\t\t\t ------------------------------------" << endl;
	}
	system("PAUSE");
	if (CurrentId == "admin")
	{
		adminmenu();
	}
	empmenu();
}
void SSystem::EditTask()
{
	string userName, NameOfTask;
	system("cls");
	cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>            Edit Task:          <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	if (CurrentId == "admin")
	{
		cout << "\n\t\t\t\t\t Enter Employee's Name: ";
		cin >> userName;
	}
	else
	{
		userName = CurrentId;
	}

	if (mapOfEmployees.find(userName) != mapOfEmployees.end())
	{
		cout << "\n\t\t\t\t\t Enter Task's name: ";
		cin.ignore();
		getline(cin, NameOfTask);
		priority_queue<Task, vector<Task>, Priority_value_sorter>q = mapOfEmployees[userName].GetQueue();
		priority_queue<Task, vector<Task>, Priority_value_sorter>newqueue;
		bool flag = false;
		Task t1;
		while (!q.empty())
		{
			if (q.top().task_name == NameOfTask)
			{
				string c, e;
				flag = true;
				Task t(q.top().id, q.top().task_name, q.top().task_description, q.top().assigned_date, q.top().due_date, q.top().priority_value);
				system("cls");
				if (CurrentId == "admin")
				{
					cout << "\n\t\t\t\t\t ------------------------------------" << endl;
					cout << "\t\t\t\t\t >>      Choose What To Edit:      <<" << endl;
					cout << "\t\t\t\t\t ------------------------------------" << endl;
					cout << "\n\t\t\t\t\t  1.Change Priority Value";
					cout << "\n\t\t\t\t\t  2.Change Task Name";
					cout << "\n\t\t\t\t\t  3.Change Task Desrciption";
					cout << "\n\t\t\t\t\t  4.Postpone Task";
					cout << "\n\t\t\t\t\t  5.Assign To Another Employee";
					cout << "\n\n\t\t\t\t\t >> Choice Options: [1/2/3/4/5]  <<";
					cout << "\n\t\t\t\t\t ------------------------------------" << endl;
					cout << "\n\t\t\t\t\t          Enter Your Choice: ";
				}
				else
				{
					cout << "\n\t\t\t\t\t ------------------------------------" << endl;
					cout << "\t\t\t\t\t >>      Choose What To Edit:      <<" << endl;
					cout << "\t\t\t\t\t ------------------------------------" << endl;
					cout << "\n\t\t\t\t\t  1.Change Priority Value";
					cout << "\n\t\t\t\t\t  2.Change Task Name";
					cout << "\n\t\t\t\t\t  3.Change Task Desrciption";
					cout << "\n\t\t\t\t\t  4.Postpone Task";
					cout << "\n\n\t\t\t\t\t >>   Choice Options: [1/2/3/4]  <<";
					cout << "\n\t\t\t\t\t ------------------------------------" << endl;
					cout << "\n\t\t\t\t\t          Enter Your Choice: ";
				}
				cin >> c;
				if (c == "1")
				{
					int x;
					cout << "\n\t\t\t\t\t Enter New Priority Value (From 1 to 10): ";
					cin >> x;
					while (!cin.good()) // validation  input should be integer
					{
						cout << "\n\t\t\t\t\t Error: Please Enter Integer Number!";
						cin.clear(); //clear cin
						cin.ignore(INT_MAX, '\n');//then ignore data
						cout << "\n\t\t\t\t\t Enter Priority Value (From 1 to 10): ";
						cin >> x;//then get  input Again
						while (x < 1 || x > 10) 
						{
							cout << "\n\t\t\t\t\t Error: Please Enter Value From 1 To 10: ";
							cin >> x;
						}
					}
					while (x < 1 || x > 10) {
						cout << "\n\t\t\t\t\t Error: Please Enter Value From 1 To 10: ";
						cin >> x;
						while (!cin.good()) // validation  input should be integer
						{
							cout << "\n\t\t\t\t\t Error: Please Enter Integer Number!";
							cin.clear(); //clear cin
							cin.ignore(INT_MAX, '\n');//then ignore data
							cout << "\n\t\t\t\t\t Enter Priority Value (From 1 to 10): ";
							cin >> x;//then get  input Again
							while (x < 1 || x > 10)
							{
								cout << "\n\t\t\t\t\t Error: Please Enter Value From 1 To 10: ";
								cin >> x;
							}
						}
					}
					t.SetPriorityValue(x);
					t1 = t;
					cout << "\n\t\t\t\t\t Priority Value Changed.\n";
				}
				else if (c == "2")
				{
					cout << "\n\t\t\t\t\t Enter New Task Name: ";
					cin.ignore();
					getline(cin, e);
					t.SetTaskName(e);
					t1 = t;
					cout << "\n\t\t\t\t\t Task Name Changed.\n";
				}
				else if (c == "3")
				{
					cout << "\n\t\t\t\t\t Enter New Task Description: ";
					cin.ignore();
					getline(cin, e);
					t.SetDes(e);
					t1 = t;
					cout << "\n\t\t\t\t\t Task Description Changed.\n";
				}
				else if (c == "4")
				{
					cout << "\n\t\t\t\t\t Postpone Task: ";
					cin >> e;
					t.SetDueDate(e);
					t1 = t;
					cout << "\n\t\t\t\t\t Task Time Extended.\n";
				}
				else if (c == "5" && CurrentId == "admin")
				{
					cout << "\n\t\t\t\t\t Enter The Employee's Name: ";
					cin >> e;
					t.SetId(e);
					t1 = t;
					cout << "\n\t\t\t\t\t Assigned To New Employee.\n";
				}
				else
				{
					cout << "\n\t\t\t\t\t Wrong Choice! - Nothing Changed.\n";
					cout << "\t\t\t\t\t------------------------------------" << endl;
					system("PAUSE");
					EditTask();
				}
				newqueue.push(t);
			}
			else
			{
				newqueue.push(q.top());
			}
			q.pop();
		}
		if (flag) {
			mapOfEmployees[userName].SetQueue(newqueue);
			priority_queue<Task, vector<Task>, Priority_value_sorter>qsystem;
			while (!AllTasks.empty())
			{
				if (AllTasks.top().id == userName && AllTasks.top().task_name == NameOfTask)
				{
					qsystem.push(t1);
				}
				else
				{
					qsystem.push(AllTasks.top());
				}
				AllTasks.pop();
			}
			AllTasks = qsystem;
			vector<Task>v;
			for (auto i : vectorOfTasks)
			{
				if (i.id == userName && i.task_name == NameOfTask)
				{
					v.push_back(t1);
				}
				else
				{
					v.push_back(i);
				}
			}
			vectorOfTasks = v;
		}
		else
		{
			cout << "\n\t\t\t\t\t Invalid Task Name.\n";
		}
	}
	else
	{
		cout << "\n\t\t\t\t\t No Employee Named '" << userName << "'.\n";

	}
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	system("PAUSE");
	if (CurrentId == "admin")
	{
		adminmenu();
	}
	else
	{
		empmenu();
	}
}
void SSystem::adminmenu()
{
	string choice;
	system("cls");
	cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>   EMPLOYEE MANAGEMENT SYSTEM   <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t  1. View All Employees In System" << endl;
	cout << "\t\t\t\t\t  2. View All Tasks In System" << endl;
	cout << "\t\t\t\t\t  3. Add New Task" << endl;
	cout << "\t\t\t\t\t  4. Edit Task" << endl;
	cout << "\t\t\t\t\t  5. Remove Task" << endl;
	cout << "\t\t\t\t\t  6. Logout" << endl;
	cout << "\t\t\t\t\t  7. Close Program" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >> Choice Options: [1/2/3/4/5/6/7]<<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	cout << "\n\t\t\t\t\t        Enter Your Choice: ";
	cin >> choice;
	if (choice == "1")
	{
		ViewAllUsersInSystem();
	}
	else if (choice == "2")
	{
		ViewAllTasksInSystem();
	}
	else if (choice == "3")
	{
		AddNewTask();
	}
	else if (choice == "4")
	{
		EditTask();
	}
	else if (choice == "5")
	{
		CompleteTask();
	}
	else if (choice == "6")
	{
		cout << "\n\n\t\t\t\t\t |          Logging Out...          |\n\t\t\t\t\t ";
		for (int a = 1; a < 5; a++)
		{
			Sleep(500);
			cout << "......";
		}
		open();
	}
	else if (choice == "7")
	{
		cout << "\n\n\t\t\t\t\t Thank you for using our Program!\n\n";
		exit(0);
	}
	else
	{
		cout << "\n\t\t\t\t\t Wrong Choice! - Select Again..\n";
		system("PAUSE");
		adminmenu();
	}
}
void SSystem::empmenu()
{
	string choice;
	system("cls");
	cout << "\n\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>           TASK MANAGER         <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	cout << "\n\t\t\t\t\t             REMINDER!" << endl;
	cout << "\t\t\t\t\t Your Next Task To Be Done Is: ";
	Reminder();
	cout << "\n\t\t\t\t\t  1. Your Tasks" << endl;
	cout << "\t\t\t\t\t  2. Complete Task" << endl;
	cout << "\t\t\t\t\t  3. Edit Task" << endl;
	cout << "\t\t\t\t\t  4. Logout" << endl;
	cout << "\t\t\t\t\t  5. Close Program" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t >>   Choice Options: [1/2/3/4/5]  <<" << endl;
	cout << "\t\t\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t\t\t        Enter Your Choice: ";
	cin >> choice;
	if (choice == "1")
	{
		EmpTasks();
	}
	else if (choice == "2")
	{
		CompleteTask();
	}
	else if (choice == "3")
	{
		EditTask();
	}
	else if (choice == "4")
	{
		cout << "\n\t\t\t\t\t |           Logging Out...         |\n\t\t\t\t\t ";
		for (int a = 1; a < 5; a++)
		{
			Sleep(500);
			cout << "......";
		}
		open();
	}
	else if (choice == "5")
	{
		cout << "\n\n\t\t\t\t\t Thank you for using our Program!\n\n";
		exit(0);
	}
	else
	{
		cout << "\n\t\t\t\t\t Wrong Choice! - Select Again..\n";
		system("PAUSE");
		empmenu();
	}
}
void SSystem::open()
{
	system("cls");
	int i = 0;
	string choice, user, password;
	char ch;
	system("cls");
	cout << "\n\t\t\t\t\t ------------------------------------";
	cout << "\n\t\t\t\t\t ||WELCOME TO EMPLOYEE TASK MANAGER||";
	cout << "\n\t\t\t\t\t ------------------------------------\n";
	cout << "\n\t\t\t\t\t  1. Login As Admin" << endl;
	cout << "\t\t\t\t\t  2. Login As Employee" << endl;
	cout << "\t\t\t\t\t  3. Register New Employee" << endl;
	cout << "\t\t\t\t\t  4. Close Program" << endl;
	cout << "\n\t\t\t\t\t ------------------------------------";
	cout << "\n\t\t\t\t\t >>   Choice Options: [1/2/3/4]    <<";
	cout << "\n\t\t\t\t\t ------------------------------------\n";
	cout << "\n\t\t\t\t\t         Enter Your Choice: ";
	cin >> choice;
	if (choice == "1")
	{
		system("cls");
		cout << "\n\t\t\t\t\t ------------------------------------";
		cout << "\n\t\t\t\t\t >>          LOGIN ADMIN           <<";
		cout << "\n\t\t\t\t\t ------------------------------------";
		cout << "\n\n\t\t\t\t\t Enter Your Username: ";
		cin >> user;
		cout << "\n\t\t\t\t\t Enter Your Password: ";
		ch = _getch();
		while (ch != 13)
		{
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		cout << "\n\n\n\t\t\t\t\t |         Verfiying ADMIN          |\n\t\t\t\t\t ";
		for (int a = 1; a < 8; a++)
		{
			Sleep(500);
			cout << ".....";
		}
		if (mapOfAdmins.find(user) == mapOfAdmins.end())
		{
			cout << "\n\n\t\t\t\t\t           Invalid Username!\n\n";
			system("PAUSE");
			open();
		}
		else
		{
			if (mapOfAdmins[user].GetPassword_Admin() == password)
			{
				CurrentId = user;
				cout << "\n\n\t\t\t\t\t           Access Granted..\n\n";
				system("PAUSE");
				system("cls");
				adminmenu();
			}
			else
			{
				cout << "\n\n\t\t\t\t\t           Wrong Password!\n\n";
				system("PAUSE");
				system("cls");
				open();
			}
		}
	}
	else if (choice == "2")
	{
		system("cls");
		cout << "\n\t\t\t\t\t ------------------------------------";
		cout << "\n\t\t\t\t\t >>        LOGIN EMPLOYEE          <<";
		cout << "\n\t\t\t\t\t ------------------------------------";
		cout << "\n\n\t\t\t\t\t Enter Your Username: ";
		cin >> user;
		cout << "\n\t\t\t\t\t Enter Your Password: ";
		ch = _getch();
		while (ch != 13)
		{
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		cout << "\n\n\n\t\t\t\t\t |        Verfiying Employee        |\n\t\t\t\t\t ";
		for (int a = 1; a < 8; a++)
		{
			Sleep(500);
			cout << ".....";
		}
		if (mapOfEmployees.find(user) == mapOfEmployees.end())
		{

			cout << "\n\n\t\t\t\t\t          Wrong Username!\n\n";
			system("PAUSE");
			system("cls");
			open();
		}
		else
		{
			if (mapOfEmployees[user].GetEmpPass() == password)
			{
				CurrentId = user;
				cout << "\n\n\t\t\t\t\t          Access Granted..\n\n";
				system("PAUSE");
				system("cls");
				empmenu();
			}
			else
			{
				cout << "\n\n\t\t\t\t\t          Wrong Password!\n\n";
				system("PAUSE");
				system("cls");
				open();
			}
		}
	}
	else if (choice == "3")
	{
		string userName, password, jobTitle;
		system("cls");
		cout << "\n\t\t\t\t\t ------------------------------------";
		cout << "\n\t\t\t\t\t >>     REGISTRATION EMPLOYEE      <<";
		cout << "\n\t\t\t\t\t ------------------------------------";
		cout << "\n\n\t\t\t\t\t Enter Your Name: ";
		cin >> userName;
		cout << "\n\t\t\t\t\t Enter Your Password: ";
		ch = _getch();
		while (ch != 13)
		{
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		cout << "\n\n\t\t\t\t\t Enter Your Job Title: ";
		cin.ignore();
		getline(cin, jobTitle);
		if (mapOfEmployees.find(userName) == mapOfEmployees.end())
		{
			Employee e(userName, password, jobTitle);
			mapOfEmployees[userName] = e;
			cout << "\n\n\t\t\t\t\t |        Saving Your Data..        |\n\t\t\t\t\t ";
			for (int a = 1; a < 8; a++)
			{
				Sleep(500);
				cout << ".....";
			}
			cout << "\n\n\t\t\t\t\t       Registered Succesfully!";
			cout << "\n\t\t\t\t\t ------------------------------------\n";
		}
		else
		{
			cout << "\n\t\t\t\t\t        Username Already Exists!";
			cout << "\n\t\t\t\t\t ------------------------------------\n";
		}
		system("PAUSE");
		open();
	}
	else if (choice == "4")
	{
		cout << "\n\n\t\t\t\t\t Thank you for using our Program!\n\n";
		exit(0);
	}
	else
	{
		cout << "\t\t\t\t\t Wrong Choice! - Select again..\n";
		system("PAUSE");
		system("cls");
		open();
	}
}
