#include <iostream>
#include "Authorization.h"

User* Login(User** users, int usersCount, string enteredLogin, string enteredPassword)
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

PaidUser* Login(PaidUser** paidUsers, int paidUsersCount, string enteredLogin, string enteredPassword)
{
	for (int i = 0; i < paidUsersCount; i++)
	{
		if (paidUsers[i]->GetLogin() == enteredLogin) 
		{ 
			if (paidUsers[i]->IsCorrectPassword(enteredPassword)) 
			{ 
				return paidUsers[i];
			} 
			else 
			{ 
				throw exception("Uncorrect password");
			} 
		}
	}  
	return nullptr;
}
