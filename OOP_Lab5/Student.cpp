
#include <iostream>
#include "Student.h"
using namespace std;

void Student::GetStudent(int numberOfRecordBook, int yearOfReceipt)
{
	this->_numberOfRecordBook = numberOfRecordBook;
	this->_yearOfReceipt = yearOfReceipt;
}

void Student::SetStudent()
{
	SetPerson();
	cout << "�������� ������ �" << this->_numberOfRecordBook << endl;
	cout << "��� ����������� ��������: " << this->_yearOfReceipt << endl;
}

Student::Student(string name, string surname, string patronymic, int numberOfRecordBook, int yearOfReceipt) : Person(name, surname, patronymic)
{
	GetStudent(numberOfRecordBook, yearOfReceipt);
}
