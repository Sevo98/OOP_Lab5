#include <iostream>
#include "Product.h"

void Product::SetProduct(string name, double price, CategoryType category)
{
	if (100000 < price < 0)
	{
		throw exception("���� ������ ���� � ��������� �� 0 �� 100 000!");
	}

	this->_name = name;
	this->_price = price;
	this->_category = category;
}

void Product::GetProduct()
{
	cout << "�������: " << this->_name << endl;
	cout << "����: " << this->_price << endl;
	cout << "��������� ������: ";
	switch (this->_category)
	{
	case 1: { cout << "�������� �����" << endl; }; break;
	case 2: { cout << "�������� ���������" << endl; }; break;
	case 3: { cout << "������������ ���������" << endl; }; break;
	case 4: { cout << "������ ���������" << endl; }; break;
	case 5: { cout << "�������" << endl; }; break;
	}
}

void Product::SetPrice(double price)
{
	if (100000 < price < 0)
	{
		throw exception("���� ������ ���� � ��������� �� 0 �� 100 000!");
	}
	this->_price = price;
}

string Product::GetName()
{
	return this->_name;
}

double Product::GetPrice()
{
	return this->_price;
}

double Product::GetCategory()
{
	return this->_category;
}

Product::Product()
{
}

Product::Product(string name, double price, CategoryType category)
{
	SetProduct(name, price, category);
}
