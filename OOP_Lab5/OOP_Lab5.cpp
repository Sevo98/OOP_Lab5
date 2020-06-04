#include <iostream>
#include <Windows.h>
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
	//Наследование
	Person person = Person("Igor", "Igorev", "Igorevich");
	ShowName(&person);

	Student student = Student("Иванов", "Иван", "Иванович", 75, 2018);
	//student.SetStudent();
	ShowName(&student);
	Teacher teacher = Teacher("Петров", "Петр", "Петрович");
	//teacher.SetTeacher();
	ShowName(&teacher);
	
	//Рефакторинг с выделением базового класса
	Post post = Post("Пост", "Текст..");

	PaidUser user = PaidUser(70, "login", "password", &post, 1);
	
	cout << "Login" << user.GetLogin() << endl;
	user.GetPosts();
 
	string pass = "12345";
	if (user.IsCorrectPassword(pass) == false)
	{
		cout << "Wrong password!" << endl;
	}
}

void ShowName(Person* person)
{
	person->SetPerson();
}
