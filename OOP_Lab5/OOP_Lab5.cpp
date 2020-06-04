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
	//������������
	Person person = Person("Igor", "Igorev", "Igorevich");
	ShowName(&person);

	Student student = Student("������", "����", "��������", 75, 2018);
	//student.SetStudent();
	ShowName(&student);
	Teacher teacher = Teacher("������", "����", "��������");
	//teacher.SetTeacher();
	ShowName(&teacher);
	
	//����������� � ���������� �������� ������
	Post post = Post("����", "�����..");

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
