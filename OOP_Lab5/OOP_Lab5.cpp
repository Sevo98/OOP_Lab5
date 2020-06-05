#include <iostream>
#include <Windows.h>
#include "CheckInput.h"
#include "Student.h"
#include "Teacher.h"
#include "Post.h"
#include "PaidUser.h"
using namespace std;

void ShowName(Person* person);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	while (true)
	{
		int number = 0;
		cout << "Введите от 1 до 4" << endl;
		cout << "1. Наследование" << endl;
		cout << "2. Рефакторинг с выделением базового класса" << endl;
		CheckInput::CheckInputInt(&number);
		switch (number)
		{
			//Наследование
		case 1:
		{
			Person person = Person("Igor", "Igorev", "Igorevich");
			ShowName(&person);

			Student student = Student("Иванов", "Иван", "Иванович", 75, 2018);
			//student.SetStudent();
			ShowName(&student);
			Teacher teacher = Teacher("Петров", "Петр", "Петрович");
			//teacher.SetTeacher();
			ShowName(&teacher);
		} break;
		//Рефакторинг с выделением базового класса
		case 2:
		{
			User* users = new User  [8] 
			{   
				User(100000, "morkovka1995", "1995morkovka"),
				User(100001, "ilon_mask", "X æ A-12"), 
				User(100002, "megazver", "password"), 
				User(100003, "yogurt", "ksTPQzSu"), 
				PaidUser(200000, "TheKnyazz", "JHPzPGFG"),
				PaidUser(200001, "system_exe", "UgfkDGmU"),
				PaidUser(200002, "RazorQ", "TBgRnbCP"),
				PaidUser(200003, "schdub", "CetyQVID"),

			};

			User* loginUsers[8];
				for (int i = 0; i < 8; i++)
				{
					loginUsers[i]= &users[i];
				}

			string login = "RazorQ";  
			string password = "TBgRnbCP";

			for (int i = 0; i < 8; i++)
			{
				if (loginUsers[i]->Login(loginUsers, 8, login, password) == nullptr)
				{
					cout << "Такого пользователя нет" << endl;
				}
				else cout << "Signed in as: " << login << endl; break;
			}

			PaidUser* paidUsers = new PaidUser[4]
			{
				PaidUser(200000, "TheKnyazz", "JHPzPGFG"),
				PaidUser(200001, "system_exe", "UgfkDGmU"),
				PaidUser(200002, "RazorQ", "TBgRnbCP"),
				PaidUser(200003, "schdub", "CetyQVID"),
			};
			User* checkLoginUsers[4];
			for (int i = 0; i < 4; i++)
			{
				checkLoginUsers[i] = &paidUsers[i];
			}
			
			login = "system_exe";
			password = "UgfkDGmU";

			for (int i = 0; i < 4; i++)
			{
				if (checkLoginUsers[i]->Login(checkLoginUsers, 4, login, password) == nullptr)
				{
					cout << "Такого пользователя нет" << endl;
				}
				else cout << "Signed in as: " << login << endl; break;
			}

			
			
			PaidUser paidUser = PaidUser(5, "Имя", "пароль");
			User poorUser = User(7, "Николай", "пасс");

			//delete[] users;
			//delete[] paidUsers;
			//delete loginUsers;
			//delete checkLoginUsers;

		} break;
		}
	}
	
}

void ShowName(Person* person)
{
	person->SetPerson();
}
