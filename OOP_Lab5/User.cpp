#include "User.h"

void User::SetId(int id)
{
	_id = id;
}

void User::SetLogin(string login)
{
	_login = login;
}

void User::SetPassword(string password)
{
	_password = password;
}

int User::GetId()
{
	return _id;
}

string User::GetLogin()
{
	return _login;
}

string User::GetPassword()
{
	return _password;
}

User::User(int id, string login, string password)
{
	SetId(id);  
	SetLogin(login);
	SetPassword(password);
}

bool User::IsCorrectPassword(string password)
{
	return (password == _password);
}
