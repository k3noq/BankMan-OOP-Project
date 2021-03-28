/*
Login podaci:
    1. Korisnik:
              Korisnik 1 - Br. računa: 123456
              	   	 - Password: adi1234

              Korisnik 2 - Br. računa: 642345
	             	 - Password: kenan1

              Korisnik 3 - Br. računa: 456723
              	   	 - Password: emrah33

    2. Radnik:
              Radnik 1 - ID: 11
                       - Password: 123pass

              Radnik 2 - ID: 12
                       - Password: emp123

              Radnik 3 - ID: 13
                       - Password: kenks45

    3. Direktor:  	
              Password: 123boss
*/
#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <ctime>
#include <locale>
#include <locale.h>

#include "Person.h"
#include "User.h"
#include "Employee.h"
#include "Boss.h"

void loadUsers(std::ifstream& file, std::vector<std::shared_ptr<User>>& users)
{
	std::string jmbg;
	std::string firstName, lastName;
	int age;
	bool gender;
	bool userStudent;
	std::string cardNum;
	int cardCVVNum;
	std::string cardExpirationDate;
	float userMonthlyFee;
	int accountNum;
	float accountBalance;
	float accountLimit;
	bool accountOpen;
	unsigned long long encryptedPassword;


	while (file >> jmbg)
	{
		file >> firstName;
		file >> lastName;
		file >> age;
		file >> gender;
		file >> userStudent;
		file >> cardNum;
		file >> cardCVVNum;
		file >> cardExpirationDate;
		file >> userMonthlyFee;
		file >> accountNum;
		file >> accountBalance;
		file >> accountLimit;
		file >> accountOpen;
		file >> encryptedPassword;

		std::shared_ptr<User> user(new User(jmbg, firstName, lastName, age, gender, userStudent, cardNum,
			cardCVVNum, cardExpirationDate, userMonthlyFee, accountNum, accountBalance, accountLimit, accountOpen, encryptedPassword));
		users.push_back(user);
	}
}

void saveUsers(std::vector<std::shared_ptr<User>>& users)
{
	std::ofstream file("users.txt");

	for (int i = 0; i < users.size(); i++)
	{
		file << users[i]->getJMBG() << " " << users[i]->getFirstName() << " " << users[i]->getLastName() << " " << users[i]->getAge() << " "
			<< users[i]->getGender() << " " << users[i]->getUserStudent() << " " << users[i]->getCardNum() << " "
			<< users[i]->getCardCVVNum() << " " << users[i]->getCardExpirationDate() << " " << users[i]->getUserMonthlyFee() << " "
			<< users[i]->getAccountNum() << " " << users[i]->getAccountBalance() << " " << users[i]->getAccountLimit() << " "
			<< users[i]->getAccountOpen() << " " << users[i]->getEncryptedPassword() << "\n";
	}
	file.close();
}


void loadEmployees(std::ifstream& file, std::vector<std::shared_ptr<Employee>>& employees)
{
	std::string jmbg;
	std::string firstName, lastName;
	int age;
	bool gender;
	int employeeID;
	std::string education;
	int position;			//1 - desk, 2 - accountant, 3 - manager
	float weeklyWorkHours;
	float positionCoefficient;
	float salary;
	std::string dateEmployed;
	std::string dateContractExpires;
	std::string address;
	std::string phoneNum;
	unsigned long long encryptedPassword;

	while (file >> jmbg)
	{
		file >> firstName;
		file >> lastName;
		file >> age;
		file >> gender;
		file >> employeeID;
		file >> education;
		file >> position;
		file >> weeklyWorkHours;
		file >> positionCoefficient;
		file >> salary;
		file >> dateEmployed;
		file >> dateContractExpires;
		file >> address;
		file >> phoneNum;
		file >> encryptedPassword;

		std::shared_ptr<Employee> employee(new Employee(jmbg, firstName, lastName, age, gender, employeeID,
			education, position, weeklyWorkHours, positionCoefficient, salary, dateEmployed, dateContractExpires,
			address, phoneNum, encryptedPassword));

		employees.push_back(employee);
	}
}

void saveEmployees(std::vector<std::shared_ptr<Employee>>& employees)
{
	std::ofstream file("employees.txt");

	for (int i = 0; i < employees.size(); i++)
	{
		file << employees[i]->getJMBG() << " " << employees[i]->getFirstName() << " " << employees[i]->getLastName() << " " << employees[i]->getAge() << " "
			<< employees[i]->getGender() << " " << employees[i]->getEmpoloyeeID() << " " << employees[i]->getEducation() << " "
			<< employees[i]->getPosition() << " " << employees[i]->getWeeklyWorkHours() << " " << employees[i]->getPositionCofficient() << " "
			<< employees[i]->getSalary() << " " << employees[i]->getDateEmployed() << " " << employees[i]->getDateContractExpires() << " "
			<< employees[i]->getAddress() << " " << employees[i]->getPhoneNum() << " " << employees[i]->getEncryptedPassword() << "\n";
	}
	file.close();
}

int main()
{
	setlocale(LC_ALL, "");

	enum {
		exit = 0, user, admin, superuser
	};

	std::cout << "\n\t********************************************************************************************\n";
	std::cout << "\t\t\t\t\t\tBANK MAN\n";
	std::cout << "\t********************************************************************************************\n";

	int option = 1;

	std::ifstream dataFileUsers("users.txt");

	if (!dataFileUsers.is_open())
	{
		std::cout << "\n\n\tGreska pri ucitavanju korisnika, molimo obratite se zaposleniku";
		return 0;
	}
	std::vector<std::shared_ptr<User>> users;
	loadUsers(dataFileUsers, users);


	std::ifstream dataFileEmployees("employees.txt");

	if (!dataFileEmployees.is_open())
	{
		std::cout << "\n\n\tGreska pri ucitavanju korisnika, molimo obratite se zaposleniku";
		return 0;
	}
	std::vector<std::shared_ptr<Employee>> employees;
	loadEmployees(dataFileEmployees, employees);

	while (true)
	{
		try
		{
			std::cout << "\n\t------------------------------------------\n";
			std::cout << "\t\t\tMAIN MENU\n";
			std::cout << "\t------------------------------------------\n";

			std::cout << "\n\t\tDobrodosli u nasu banku!\n";
			std::cout << "\tMolimo izaberite jednu od ponudjenih opcija.";

			std::cout << "\n\n\t------------------------------------------\n";
			std::cout << "\n\t\t1 - Korisnik"
				<< "\n\t\t2 - Radnik"
				<< "\n\t\t3 - Direktor"
				<< "\n\t\t0 - Exit\n\n";
			std::cout << "\t------------------------------------------\n";
			std::cout << "\n\t\tIzbor: ";

			std::cin >> option;
			option = inputCheck(option);


			if (option == exit)
			{
				std::cout << "\n\n\t\tOdabrali ste exit!\n";
				std::cout << "\n\t\tHvala sto ste izabrali nas!\n\n\n\n";
				break;
			}
			else if (option == user)
			{
				std::cout << "\n\n\t\tOdabrali ste opciju korisnik!\n";
				pause();
				userDriverFunction(users);
			}
			else if (option == admin)
			{
				std::cout << "\n\n\t\tOdabrali ste opciju radnik!\n\t";
				pause();
				employeeDriverFunction(users, employees);
			}
			else if (option == superuser)
			{
				std::cout << "\n\n\t\tOdabrali ste opciju direktor!\n\t";
				pause();
				bossDriverFunction(employees);
			}
			else
			{
				std::cout << "\n\n\t\tNepostojeca opcija!";
				std::cout << "\n\t\tMolimo izaberite jednu od ponudjenih cifara (0,1,2,3)\n\n\t\t";
				pause();
			}
			system("cls");
		}
		catch (const char greska[])
		{
			std::cout << greska;
		}
		catch (...)
		{
			std::cout << "\n\tGreska u programu";
		}
	}
	saveUsers(users);
	saveEmployees(employees);
}
