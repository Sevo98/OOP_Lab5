#include <iostream>
#include "Person.h"
using namespace std;

void Person::GetPerson(string name, string surname, string patronymic)
{
	this->_name = name;
	this->_surname = surname;
	this->_patronymic = patronymic;
}

void Person::SetPerson()
{
	cout << "Фамилия: " << this->_surname << endl;
	cout << "Имя: " << this->_name << endl;
	cout << "Отчество: " << this->_patronymic << endl;
}

Person::Person(string name, string surname, string patronymic)
{
	GetPerson(name, surname, patronymic);
}
