#pragma once
#include <string>
using namespace std;

class Person
{
	string _name;
	string _surname;
	string _patronymic;
public:
	void GetPerson(string name, string surname, string patronymic);
	void SetPerson();

	Person(string name, string surname, string patronymic);
};

