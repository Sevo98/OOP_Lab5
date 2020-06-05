#include "User.h"
#include <vector>

void User::SetId(int id)
{
	_id = id;
}

void User::SetLogin(string login)
{
	int g = size(login);
	
	vector<char> v(login.begin(), login.end());
	int symbols = 11;
	string check = { "{}<>@#$%^:*" };
	
	for (int i = 0; i < g; i++)
	{
		for (int j = 0; j < symbols; j++)
		{
			if (login[i] == check[j])
			{
				throw exception("Недопустимый символ! Запрещены символы {}<>@#$%^:*");
			}
		}
	}
	
	
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

User* User::Login(User** users, int usersCount, string enteredLogin, string enteredPassword)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]->GetLogin() == enteredLogin)
		{
			if (users[i]->IsCorrectPassword(enteredPassword))
			{
				return users[i];
			}
			else
			{
				throw exception("Uncorrect password");
			}
		}
	}
	return nullptr;
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
