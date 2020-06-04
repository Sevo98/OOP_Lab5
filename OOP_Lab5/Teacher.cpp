#include "Teacher.h"

void Teacher::SetTeacher()
{
	SetPerson();
}

Teacher::Teacher(string name, string surname, string patronymic) : Person(name, surname, patronymic)
{
}
