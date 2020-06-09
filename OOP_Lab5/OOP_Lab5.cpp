#include <iostream>
#include <Windows.h>
#include "CheckInput.h"
#include "Student.h"
#include "Teacher.h"
#include "Post.h"
#include "PaidUser.h"
#include "Product.h"
#include "DiscountBase.h"
#include "PercentDiscount.h"
#include "CertificateDiscount.h"
#include "UniformDistanceCalculator.h"
#include "AcceleratedDistanceCalculator.h"
using namespace std;

void ShowName(Person* person);
void ShowCheckWithDiscount(DiscountBase* discount, Product* products, int productsCount);

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
		cout << "3. Полиморфизм" << endl;
		cout << "4. Индивидуальное задание" << endl;
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

			string login = "Razor";  
			string password = "TBgRnbP";

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

			//for (int i = 0; i < 8; i++)
			//{
			//	delete loginUsers[i];
			//}
			//delete loginUsers;

			//for (int i = 0; i < 8; i++)
			//{
			//	delete& users[i];
			//}
			//delete[] users;
			//for (int i = 0; i < 4; i++)
			//{
			//	delete& paidUsers[i];
			//}
			//delete[] paidUsers;
			//for (int i = 0; i < 4; i++)
			//{
			//	checkLoginUsers[i];
			//}
			//delete checkLoginUsers;

		} break;

		//Полиморфизм
		case 3:
		{
			const int productsCount = 4;
			Product products[productsCount];
			products[0] = Product("Курица", 250, meat);
			products[1] = Product("Кефир", 55, milk_products);
			products[2] = Product("Domestos", 300, household_chemicals);
			products[3] = Product("Молоко", 80, milk_products);

			PercentDiscount* percentDicsount = new PercentDiscount(50, milk_products);
			CertificateDiscount* certificate = new CertificateDiscount(500, household_chemicals);

			DiscountBase* arrDiscounts[2];
			arrDiscounts[0] = percentDicsount;
			arrDiscounts[1] = certificate;


			ShowCheckWithDiscount(arrDiscounts[0], products, productsCount);

			/*delete percentDicsount;
			delete certificate;
			delete[] arrDiscounts;*/
		} break;
		//Индивидуальное задание
		case 4:
		{
			system("cls");
			while (true)
			{
				int selectCalc = 0;
				cout << "Введите от 1 до 4" << endl;
				cout << "1. Расчет расстояния для равномерного движения" << endl;
				cout << "2. Расчет расстояния для равноускоренного движения" << endl;
				CheckInput::CheckInputInt(&selectCalc);
				switch (selectCalc)
				{
				case 1: 
				{
					double speed, time;
					cout << "Введите скорость: ";
					CheckInput::CheckInputDouble(&speed);
					cout << "Введите время: ";
					CheckInput::CheckInputDouble(&time);
					UniformDistanceCalculator calculator = UniformDistanceCalculator(speed);
					cout << "Расстояние, пройденное за " << time << ": " << calculator.Calculate(time) << endl;
				} break;

				case 2:
				{
					AcceleratedDistanceCalculator calculator = AcceleratedDistanceCalculator(60.0, 1.5);
					cout << "Расстояние, пройденное за 10 минут:" << calculator.Calculate(10) << endl;
				} break;
				}
			}
		} break;
		}
	}
	
}

void ShowName(Person* person)
{
	person->SetPerson();
}

void ShowCheckWithDiscount(DiscountBase* discount, Product* products, int productsCount)
{
	double allPrice = 0;
	for (int i = 0; i < productsCount; i++)
	{
		allPrice = allPrice + products[i].GetPrice();
	}

	for (int i = 0; i < productsCount; i++)
	{
		cout << "Старая цена товара " << products[i].GetName() << ": " << products[i].GetPrice() << endl;
		products[i].SetPrice(discount->Calculate(&products[i]));
		cout << "Цена при применении скидки: " << products[i].GetPrice() << endl;
	}

	double allPriceWithDiscount = 0;
	for (int i = 0; i < productsCount; i++)
	{
		allPriceWithDiscount = allPriceWithDiscount + products[i].GetPrice();
	}
	cout << "Цена всего списка товаров без учета скидки: " << allPrice << endl;
	cout << "Цена всего списка товаров с учетом скидки: " << allPriceWithDiscount << endl;
	cout << "Скидка составила: " << allPrice - allPriceWithDiscount << endl;
}