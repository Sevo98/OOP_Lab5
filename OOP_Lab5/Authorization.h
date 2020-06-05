#pragma once
#include "User.h"
#include "PaidUser.h"

User* Login(User** users, int usersCount, string enteredLogin, string enteredPassword);
PaidUser* Login(PaidUser** paidUsers, int paidUsersCount, string enteredLogin, string enteredPassword);