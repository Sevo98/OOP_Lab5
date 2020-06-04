#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Teacher : public Person
{
public:
	void SetTeacher();
	Teacher(string name, string surname, string patronymic);
};

