#pragma once

class Boss : public Person
{
private:
	int bossID;
	std::string education;
	std::string address;
	std::string phoneNum;
	float salary;
	unsigned long long bossPassword;

public:
	Boss() : Person(), bossID(0), education(""), address(""), phoneNum(""), salary(0), bossPassword(0) {};
	Boss(std::string jmbg, std::string firstName, std::string lastName, int age, bool gender, int bossID,
		std::string education, std::string address, std::string phoneNum, float salary, unsigned long long bossPw) :
		Person(jmbg, firstName, lastName, age, gender),
		bossID(bossID), education(education), address(address),
		phoneNum(phoneNum), salary(salary), bossPassword(bossPw) {};

	void setBossID(int bossID) {
		this->bossID = bossID;
	}

	void setEducation(std::string education)
	{
		this->education = education;
	}

	void setAddress(std::string address)
	{
		this->address = address;
	}

	void setPhoneNum(std::string phoneNum)
	{
		this->phoneNum = phoneNum;
	}

	void setSalary(float salary)
	{
		this->salary = salary;
	}

	void setBossPassword(unsigned long long bossPw)
	{
		this->bossPassword = bossPw;
	}

	int getBossID() { return this->bossID; }
	std::string getEducation() { return this->education; }
	std::string getAddress() { return this->address; }
	std::string getPhoneNum() { return this->phoneNum; }
	float getSalary() { return this->salary; }
	unsigned long long getBossPassword() { return this->bossPassword; }

	bool isAdmin()
	{
		return true;
	}

	//friend std::istream& operator>>(std::istream& stream, Boss& boss);

	friend std::ostream& operator<<(std::ostream& stream, Boss& boss)
	{
		stream << "\t\tID: " << boss.getBossID()
			<< "\n\t\tEdukacija: " << boss.getEducation()
			<< "\n\t\tAdresa: " << boss.getAddress()
			<< "\n\t\tBroj telefona: " << boss.getPhoneNum()
			<< "\n\t\tPrimanja: " << boss.getSalary();

		return stream;
	}

	~Boss() {};
};

void bossMenu()
{
	std::cout << "\n\n\tOpcije:"
		<< "\n\t\t1 - Dodavanje novog uposlenika"
		<< "\n\t\t2 - Spisak svih uposlenika"
		<< "\n\t\t3 - Brisanje uposlenika"
		<< "\n\t\t4 - Pregled informacija o direktoru"
		<< "\n\t\t0 - Izlaz"
		<< "\n\n\t\tOpcija: ";
}

void inputEmployee(std::vector<std::shared_ptr<Employee>>& employees)
{
	std::shared_ptr<Employee> employee(new Employee());

	std::cin >> *employee;
	employees.push_back(employee);
}

void printEmployees(std::vector<std::shared_ptr<Employee>>& employees)
{
	std::cout << "\n*****************************************************************\n";
	std::cout << "\t\tIspis radnika";
	std::cout << "\n*****************************************************************\n";

	for (int i = 0; i < employees.size(); i++)
	{
		std::cout << *employees[i];
	}
	std::cout << "\n";
	pause();
}

void printEmployeesToDelete(std::vector<std::shared_ptr<Employee>>& employees)
{
	std::cout << "\n\tR.br.\tIme i prezime\n";
	for (int i = 0; i < employees.size(); i++)
	{
		std::cout << "\t" << i + 1 << ". \t" << employees[i]->getFirstName() << " " << employees[i]->getLastName() << "\n";
	}
}

void deleteEmployee(std::vector<std::shared_ptr<Employee>>& employees)
{
	if (employees.size() == 0)
	{
		std::cout << "\nNema vise radnika!\n";
		return;
	}

	int inputDeleteChoice;

	do {
		std::cout << "\nUnesite redni broj uposlenika za obrisati: ";
		std::cin >> inputDeleteChoice;
		if (inputDeleteChoice < 0 || inputDeleteChoice > employees.size())
		{
			std::cout << "\n[GRESKA] Unijeli ste redni broj van opsega!\n";
		}
	} while (inputDeleteChoice < 0 || inputDeleteChoice > employees.size());

	employees.erase(employees.begin() + ((long long)inputDeleteChoice - 1));
}

void bossInfo()
{
	Boss boss;
	boss.setFirstName("Edin");
	boss.setLastName("Tabak");
	boss.setAge(30);
	boss.setGender(true);
	boss.setEducation("Mr. ekonomije i finansijskog racunovodstva");

	std::cout << "\n\t|Informacije o nasem vlasniku|";
	std::cout << "\n\t\tIme: " << boss.getFirstName();
	std::cout << "\n\t\tPrezime: " << boss.getLastName();
	std::cout << "\n\t\tGodine: " << boss.getAge();
	std::cout << "\n\t\tSpol: "; boss.getGender() ? std::cout << "Musko" : std::cout << "Zensko";
	std::cout << "\n\t\tObrazovanje: " << boss.getEducation() << "\n\n";

	pause();
}

int successfulLogin(unsigned long long encryptedPassword, Boss& boss)
{
	if (boss.getBossPassword() == encryptedPassword)
	{
		return 1;
	}
	return -1;
}

void bossDriverFunction(std::vector<std::shared_ptr<Employee>>& employees)
{
	int inputChoice;
	int bossVerification;

	std::string passwordInput;
	int numberOfTries = 3;

	Boss boss;
	boss.setFirstName("Edin");
	boss.setBossPassword(1098687);

	while (true)
	{
		std::cout << "\n\n\tMolimo unesite password: ";
		std::cin >> passwordInput;

		numberOfTries--;

		unsigned long long encryptedPassword = encryptPassword(passwordInput);
		bossVerification = successfulLogin(encryptedPassword, boss);

		if (bossVerification != -1)
		{
			std::cout << "\n\tPrijava uspjesna.\n\n";
			pause();
			break;
		}
		else if (numberOfTries > 0)
		{
			std::cout << "\n\tPogresan unos!\n\tPreostalo pokusaja: " << numberOfTries;
		}
		else
		{
			std::cout << "\n\tPogresan unos!\n\tNemate preostalih pokusaja, nalog je trenutno blokiran zbog sigurnosti vlasnika.\n\n";
			exit(0);
		}
	}

	std::cout << "\n\n\tPozdrav " << boss.getFirstName();
	std::cout << "\n\tDobrodosli na posao!\n";

	do {
		bossMenu();
		std::cin >> inputChoice;
		inputCheck(inputChoice);

		switch (inputChoice)
		{
		case 1:
			system("cls");
			inputEmployee(employees);
			break;

		case 2:
			system("cls");
			printEmployees(employees);
			break;

		case 3:
			system("cls");
			printEmployeesToDelete(employees);
			deleteEmployee(employees);
			break;

		case 4:
			system("cls");
			bossInfo();
			break;

		default:
			std::cout << "\n[GRESKA] Nepostojeca opcija\n";
			break;
		}
	} while (inputChoice != 0);
}