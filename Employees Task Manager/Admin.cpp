#include "Admin.h"

Admin::Admin()
{
}

Admin::Admin(string userName, string password)
{
	this->userName = userName;
	this->password = password;
}

string Admin::GetUserName_Admin()
{
	return userName;
}

string Admin::GetPassword_Admin()
{
	return password;
}