#pragma once
#include<iostream>
#include<string>
using namespace std;
class Admin
{
private:
	string userName;
	string password;
public:
	Admin();
	Admin(string userName, string password);
	string GetUserName_Admin();
	string GetPassword_Admin();
};