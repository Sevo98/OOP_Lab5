#pragma once 
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Student : public Person
{
	int _numberOfRecordBook;
	int _yearOfReceipt;
public:
	void GetStudent(int numberOfRecordBook, int yearOfReceipt);
	void SetStudent();

	Student(string name, string surname, string patronymic, int numberOfRecordBook, int yearOfReceipt);
};