#pragma once

class Employee : public Person
{
private:
	int employeeID;
	std::string education;	//zavrseni fakultet
	int position;			//1 - desk, 2 - accountant, 3 - manager
	float weeklyWorkHours;
	float positionCoefficient;
	float salary;
	std::string dateEmployed;
	std::string dateContractExpires;
	std::string address;
	std::string phoneNum;
	unsigned long long encryptedPassword;

public:

	Employee() : Person(),
		employeeID(0), education(""), position(1), weeklyWorkHours(0), positionCoefficient(0),
		salary(0), dateEmployed(""), dateContractExpires(""), address(""), phoneNum(""),
		encryptedPassword(0) {};


	Employee(std::string jmbg, std::string firstName, std::string lastName, int age, bool gender, int id,
		std::string edu, int pos, float wHours, float posCoeff, float sal,
		std::string dateEmpl, std::string dateExpires, std::string addr, std::string pNum, unsigned long long encPw) :
		Person(jmbg, firstName, lastName, age, gender),
		employeeID(id), education(edu), position(pos), weeklyWorkHours(wHours), positionCoefficient(posCoeff),
		salary(sal), dateEmployed(dateEmpl), dateContractExpires(dateExpires), address(addr), phoneNum(pNum), encryptedPassword(encPw) {};

	void setEmployeeID(int id) { this->employeeID = id; }
	void setEducation(std::string edu) { this->education = edu; }
	void setPosition(int pos) { this->position = pos; }
	void setWeeklyWorkHours(float wHours) { this->weeklyWorkHours = wHours; }
	void setPositionCofficient(float posCoeff) { this->positionCoefficient = posCoeff; }
	void setSalary(float sal) { this->salary = sal; }
	void setDateEmployed(std::string dateEmpl) { this->dateEmployed = dateEmpl; }
	void setDateContractExpires(std::string dateExpires) { this->dateContractExpires = dateExpires; }
	void setAddress(std::string addr) { this->address = addr; }
	void setPhoneNum(std::string pNum) { this->phoneNum = pNum; }
	void setEmployeePassword(unsigned long long encPw) { this->encryptedPassword = encPw; }

	int getEmpoloyeeID() { return this->employeeID; }
	std::string getEducation() { return this->education; }
	int getPosition() { return this->position; }
	float getWeeklyWorkHours() { return this->weeklyWorkHours; }
	float getPositionCofficient() { return this->positionCoefficient; }
	float getSalary() { return this->salary; }
	std::string getDateEmployed() { return this->dateEmployed; }
	std::string getDateContractExpires() { return this->dateContractExpires; }
	std::string getAddress() { return this->address; }
	std::string getPhoneNum() { return this->phoneNum; }
	unsigned long long getEncryptedPassword() { return this->encryptedPassword; }

	bool isAdmin()
	{
		return true;
	}

	friend std::istream& operator>>(std::istream& stream, Employee& employee)
	{
		std::string jmbg;
		std::cout << "\n\tJMBG korisnika: ";
		std::cin >> jmbg;
		employee.setJMBG(jmbg);

		std::string firstName;
		std::cout << "\n\tIme korisnika: ";
		std::cin >> firstName;
		employee.setFirstName(firstName);

		std::string lastName;
		std::cout << "\n\tPrezime korisnika: ";
		std::cin >> lastName;
		employee.setLastName(lastName);

		int age;
		std::cout << "\n\tGodine korisnika: ";
		std::cin >> age;
		age = inputCheck(age);
		employee.setAge(age);

		bool gender;
		std::cout << "\n\tSpol korisnika [0 - Musko, 1 - Zensko]: ";
		std::cin >> gender;
		gender = inputCheck(gender);
		employee.setGender(gender);

		int id;
		std::cout << "\n\tUnesite ID novog uposlenika: ";
		std::cin >> id;
		id = inputCheck(id);
		employee.setEmployeeID(id);

		std::string edu;
		std::cout << "\n\tUnesite nivo obrazovanja novog uposlenika: ";
		std::cin >> edu;
		employee.setEducation(edu);

		int pos;
		do {
			std::cout << "\n\tPozicije: 1 - recepcija, 2 - racunovodstvo, 3 - menadzer\n";
			std::cout << "\n\tUnesite radnu poziciju novog uposlenika: ";
			std::cin >> pos;
			pos = inputCheck(pos);
			if (pos < 1 || pos > 3)
			{
				std::cout << "\n\t[ERROR] Unijeli ste broj van opsega!\n";
			}
		} while (pos < 1 || pos >3);
		employee.setPosition(pos);

		float wHours;
		std::cout << "\n\tUnesite broj sedmicnih radnih sati za novog uposlenika: ";
		std::cin >> wHours;
		wHours = inputCheck(wHours);
		employee.setWeeklyWorkHours(wHours);

		const float posCoeffDesk = 1.1f, posCoeffAcc = 1.3f, posCoeffManager = 1.5f;
		if (employee.getPosition() == 1)
		{
			employee.setWeeklyWorkHours(posCoeffDesk);
		}
		else if (employee.getPosition() == 2)
		{
			employee.setWeeklyWorkHours(posCoeffAcc);
		}
		else
		{
			employee.setWeeklyWorkHours(posCoeffManager);
		}

		float sal;
		sal = employee.getWeeklyWorkHours() * employee.getPositionCofficient() * 5 * 4;
		employee.setSalary(sal);

		std::string dateEmpl;
		std::cout << "\n\tUnesite datum zaposlenja zaposlenika: ";
		std::cin >> dateEmpl;
		employee.setDateEmployed(dateEmpl);

		std::string dateExpires;
		std::cout << "\n\tUnesite isteka ugovora zaposlenika: ";
		std::cin >> dateExpires;
		employee.setDateContractExpires(dateExpires);

		std::string addr;
		std::cout << "\n\tUnesite adresu zaposlenika: ";
		std::cin >> addr;
		employee.setAddress(addr);

		std::string pNum;
		std::cout << "\n\tUnesite broj telefona zaposlenika: ";
		std::cin >> pNum;
		employee.setDateEmployed(pNum);

		return stream;
	}

	friend std::ostream& operator<<(std::ostream& stream, Employee& employee)
	{
		stream
			<< "\n\tIme i prezime: " << employee.getFirstName() << " " << employee.getLastName()
			<< "\n\tJMBG: " << employee.getJMBG()
			<< "\n\tGodine: " << employee.getAge()
			<< "\n\tSpol: " << (employee.getGender() ? "Musko." : "Zensko.");

		stream
			<< "\n\tID: " << employee.getEmpoloyeeID()
			<< "\n\tObrazovanje: " << employee.getEducation();

		stream << "\n\tPozicija: ";
		if (employee.getPosition() == 1)
		{
			stream << "Recepcija.\n";
		}
		else if (employee.getPosition() == 2)
		{
			stream << "Racunovodstvo.\n";
		}
		else
		{
			stream << "Menadzer.\n";
		}

		stream
			<< "\tSedmicno radnih sati: " << employee.getWeeklyWorkHours()
			<< "\n\tKoeficijent po poziciji: " << employee.getPositionCofficient()
			<< "\n\tPlata: " << employee.getSalary()
			<< "\n\tDatum zaposlenja: " << employee.getDateEmployed()
			<< "\n\tDatum isteka ugovora: " << employee.getDateContractExpires()
			<< "\n\tAdresa: " << employee.getAddress()
			<< "\n\tBroj telefona: " << employee.getPhoneNum() << "\n";

		return stream;
	}

	~Employee() {};
};


void employeeMenu()
{
	std::cout << "\n\n\tOpcije:"
		<< "\n\t\t1 - Unos novog korisnika"
		<< "\n\t\t2 - Ispis korisnika"
		<< "\n\t\t3 - Brisanje korisnika"
		<< "\n\t\t0 - Izlaz"
		<< "\n\n\t\tOpcija: ";
}

void inputUser(std::vector<std::shared_ptr<User>>& users)
{
	std::shared_ptr<User> user(new User());

	std::cin >> *user;
	users.push_back(user);
}

void printUsers(std::vector<std::shared_ptr<User>>& users)
{
	std::cout << "\n*****************************************************************\n";
	std::cout << "\t\tIspis korisnika";
	std::cout << "\n*****************************************************************\n";

	for (int i = 0; i < users.size(); i++)
	{
		std::cout << *users[i];
	}
	pause();
}

void printUsersToDelete(std::vector<std::shared_ptr<User>>& users)
{
	std::cout << "\n\tR.br.\tIme i prezime\n";
	for (int i = 0; i < users.size(); i++)
	{
		std::cout << "\t" << i + 1 << ". \t" << users[i]->getFirstName() << " " << users[i]->getLastName() << "\n";
	}
}

void deleteUser(std::vector<std::shared_ptr<User>>& users)
{

	if (users.size() == 0)
	{
		throw "\nNema vise radnika!\n";
		return;
	}

	int inputDeleteChoice;

	do {
		std::cout << "\nUnesite redni broj uposlenika za obrisati: ";
		std::cin >> inputDeleteChoice;
		inputDeleteChoice = inputCheck(inputDeleteChoice);
		if (inputDeleteChoice < 0 || inputDeleteChoice > users.size())
		{
			std::cout << "\n[GRESKA] Unijeli ste redni broj van opsega!\n";
		}
	} while (inputDeleteChoice < 0 || inputDeleteChoice > users.size());

	users.erase(users.begin() + ((long long)inputDeleteChoice - 1));
}

int successfulLogin(int employeeID, unsigned long long encryptedPassword, std::vector<std::shared_ptr<Employee>>& employees)
{
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getEmpoloyeeID() == employeeID and employees[i]->getEncryptedPassword() == encryptedPassword)
		{
			return i;
		}
	}

	return -1;
}

void employeeDriverFunction(std::vector<std::shared_ptr<User>>& users, std::vector<std::shared_ptr<Employee>>& employees)
{
	int inputChoice;
	int employeeIDInput;
	std::string passwordInput;
	int numberOfTries = 3;
	int employeeIndex;

	while (true)
	{
		std::cout << "\n\n\tMolimo unesite Vas ID: ";
		std::cin >> employeeIDInput;
		employeeIDInput = inputCheck(employeeIDInput);

		std::cout << "\n\n\tMolimo unesite password: ";
		std::cin >> passwordInput;

		numberOfTries--;

		unsigned long long encryptedPassword = encryptPassword(passwordInput);
		employeeIndex = successfulLogin(employeeIDInput, encryptedPassword, employees);

		if (employeeIndex != -1)
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

	std::cout << "\n\tPozdrav " << employees[employeeIndex]->getFirstName();
	std::cout << "\n\tDobrodosli na posao!\n";

	do {
		employeeMenu();
		//std::cout << "\tVas izbor: ";
		std::cin >> inputChoice;
		inputChoice = inputCheck(inputChoice);

		switch (inputChoice)
		{
		case 1:
			system("cls");
			inputUser(users);
			break;

		case 2:
			system("cls");
			printUsers(users);
			break;

		case 3:
			system("cls");
			printUsersToDelete(users);
			deleteUser(users);
			break;

		default:
			std::cout << "\n[GRESKA] Nepostojeca opcija\n";
			break;
		}
	} while (inputChoice != 0);
}