#pragma once

class User : public Person
{
private:
	bool userStudent;
	std::string cardNum;
	int cardCVVNum;
	std::string cardExpirationDate;
	float userMonthlyFee;
	unsigned long long accountNum;
	float accountBalance;
	float accountLimit;
	bool accountOpen;
	unsigned long long encryptedPassword;

public:
	User() : Person(),
		userStudent(0), cardNum(""), cardCVVNum(0), cardExpirationDate(""), userMonthlyFee(0), accountNum(0), accountBalance(0), accountLimit(0), accountOpen(0), encryptedPassword(0) {};
	User(std::string jmbg, std::string firstName, std::string lastName, int age, bool gender, bool userStudent, std::string cardNum, int cardCVVNum, std::string cardExpirationDate,
		float userMonthlyFee, unsigned long long accountNum, float accountBalance, float accountLimit, bool accountOpen, unsigned long long encryptedPassword) :
		Person(jmbg, firstName, lastName, age, gender),
		userStudent(userStudent), cardNum(cardNum), cardCVVNum(cardCVVNum), cardExpirationDate(cardExpirationDate), userMonthlyFee(userMonthlyFee), accountNum(accountNum),
		accountBalance(accountBalance), accountLimit(accountLimit), accountOpen(accountOpen), encryptedPassword(encryptedPassword) {};

	void setUserStudent(bool userStudent) { this->userStudent = userStudent; }
	void setCardNum(std::string cardNum) { this->cardNum = cardNum; }
	void setCardCVVNum(int cardCVVNum) { this->cardCVVNum = cardCVVNum; }
	void setCardExpirationDate(std::string cardExpirationDate) { this->cardExpirationDate = cardExpirationDate; }
	void setUserMonthlyFee(float userMonthlyFee) { this->userMonthlyFee = userMonthlyFee; }
	void setAccountNum(unsigned long long accountNum) { this->accountNum = accountNum; }
	void setAccountBalance(float accountBalance) { this->accountBalance = accountBalance; }
	void setAccountLimit(float accountLimit) { this->accountLimit = accountLimit; }
	void setAccountOpen(bool accountOpen) { this->accountOpen = accountOpen; }
	void setEncryptedPassword(unsigned long long encryptedPassword) { this->encryptedPassword = encryptedPassword; }

	bool getUserStudent() { return userStudent; }
	std::string getCardNum() { return cardNum; }
	int getCardCVVNum() { return cardCVVNum; }
	std::string getCardExpirationDate() { return cardExpirationDate; }
	float getUserMonthlyFee() { return userMonthlyFee; }
	unsigned long long getAccountNum() { return accountNum; }
	float getAccountBalance() { return accountBalance; }
	float getAccountLimit() { return accountLimit; }
	bool getAccountOpen() { return accountOpen; }
	unsigned long long getEncryptedPassword() { return encryptedPassword; }

	bool isAdmin()
	{
		return false;
	}

	friend std::istream& operator>>(std::istream& stream, User& user)
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
		std::string password;
		unsigned long long encryptedPassword;

		//std::cout << "\n\tMeni za kreiranje korisnika";
		std::cout << "\n\tJMBG korisnika: ";
		std::cin >> jmbg;
		std::cout << "\n\tIme korisnika: ";
		std::cin >> firstName;
		std::cout << "\n\tPrezime korisnika: ";
		std::cin >> lastName;
		std::cout << "\n\tGodine korisnika: ";
		std::cin >> age;
		age = inputCheck(age);
		std::cout << "\n\tSpol korisnika [0 - Musko, 1 - Zensko]: ";
		std::cin >> gender;
		gender = inputCheck(gender);
		std::cout << "\n\tDa li je korisnik student [0 - NE, 1 - DA]: ";
		std::cin >> userStudent;
		userStudent = inputCheck(userStudent);
		std::cout << "\n\tBroj kartice korsnika: ";
		std::cin >> cardNum;
		std::cout << "\n\tCVV: ";
		std::cin >> cardCVVNum;
		cardCVVNum = inputCheck(cardCVVNum);
		std::cout << "\n\tDatum isteka kartice: ";
		std::cin >> cardExpirationDate;
		std::cout << "\n\tMjesecna naplata: ";
		std::cin >> userMonthlyFee;
		userMonthlyFee = inputCheck(userMonthlyFee);
		std::cout << "\n\tBroj racuna: ";
		std::cin >> accountNum;
		accountNum = inputCheck(accountNum);
		std::cout << "\n\tStanje racuna: ";
		std::cin >> accountBalance;
		accountBalance = inputCheck(accountBalance);
		std::cout << "\n\tLimit racuna: ";
		std::cin >> accountLimit;
		accountLimit = inputCheck(accountLimit);
		std::cout << "\n\tPassword racuna: ";
		std::cin >> password;
		encryptedPassword = encryptPassword(password);

		user.setJMBG(jmbg);
		user.setFirstName(firstName);
		user.setLastName(lastName);
		user.setAge(age);
		user.setGender(gender);
		user.setUserStudent(userStudent);
		user.setCardNum(cardNum);
		user.setCardCVVNum(cardCVVNum);
		user.setCardExpirationDate(cardExpirationDate);
		user.setUserMonthlyFee(userMonthlyFee);
		user.setAccountNum(accountNum);
		user.setAccountBalance(accountBalance);
		user.setAccountLimit(accountLimit);
		user.setAccountOpen(true);
		user.setEncryptedPassword(encryptedPassword);

		return stream;
	}

	friend std::ostream& operator<<(std::ostream& stream, User& user)
	{
		stream << "\n\tIme i prezime: " << user.getFirstName() << " " << user.getLastName()
			<< "\n\tJMBG: " << user.getJMBG()
			<< "\n\tGodine: " << user.getAge()
			<< "\n\tSpol: " << (user.getGender() ? "Musko" : "Zensko")
			<< "\n\tBroj kreditne kartice: " << user.getCardNum()
			<< "\n\tCVV: " << user.getCardCVVNum()
			<< "\n\tKartica vazi do: " << user.getCardExpirationDate()
			<< "\n\tMjesecni utrosak: " << user.getUserMonthlyFee() << "KM"
			<< "\n\tBroj racuna: " << user.getAccountNum()
			<< "\n\tStanje racuna: " << user.getAccountBalance() << "KM"
			<< "\n\tLimit racuna: " << user.getAccountLimit() << "KM"
			<< "\n\tRacun je " << (user.getAccountOpen() ? "otvoren" : "zatvoren")
			<< "\n\n";

		return stream;
	}

	~User() {};
};


int successfulLogin(int accountNumber, unsigned long long encryptedPassword, std::vector<std::shared_ptr<User>>& users)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getAccountNum() == accountNumber and users[i]->getEncryptedPassword() == encryptedPassword)
		{
			return i;
		}
	}

	return -1;
}

void logUser(std::ostream& file, std::shared_ptr<User>& user)
{
	file << "\n*************************************************************\n";

	file << "Podaci o korisniku:\n\n";

	file << "Ime:                     " << user->getFirstName() << "\n";
	file << "Prezime:                 " << user->getLastName() << "\n";

	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	file << "Datum prijave:           " << timeinfo.tm_mday << "." << 1 + timeinfo.tm_mon << "." << 1900 + timeinfo.tm_year << "." << "\n";
	file << "Vrijeme prijave:         " << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << "\n";

	file << "\n*************************************************************\n";
}

void printTransaction(std::ostream& file, std::shared_ptr<User> user, int payment)
{
	file << "\n*************************************************************\n";

	file << "Podaci o korisniku:\n\n";

	file << "Ime:                     " << user->getFirstName() << "\n";
	file << "Prezime:                 " << user->getLastName() << "\n";

	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	file << "Datum transakcije:       " << timeinfo.tm_mday << "." << 1 + timeinfo.tm_mon << "." << 1900 + timeinfo.tm_year << "." << "\n";
	file << "Vrijeme transakcije:     " << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << "\n";
	file << "Iznos transakcije:       " << payment;
	file << "\n*************************************************************\n";
}

void completePayment(std::shared_ptr<User> user, int payment)
{
	user->setAccountBalance(user->getAccountBalance() - payment);

	std::cout << "\n\tUspjesna isplata!";
	std::cout << "\n\n\tPreostalo stanje racuna: " << user->getAccountBalance() << "KM";
}

void userDriverFunction(std::vector<std::shared_ptr<User>>& users)
{
	int accountNumber;
	std::string password;
	int numberOfTries = 3;
	int userIndex;
	unsigned long long encryptedPassword;

	while (true)
	{
		std::cout << "\n\n\tMolimo unesite broj racuna: ";
		std::cin >> accountNumber;
		accountNumber = inputCheck(accountNumber);

		std::cout << "\n\n\tMolimo unesite password: ";
		std::cin >> password;

		numberOfTries--;

		encryptedPassword = encryptPassword(password);
		userIndex = successfulLogin(accountNumber, encryptedPassword, users);
		if (userIndex != -1)
		{
			if (!users[userIndex]->getAccountOpen())
			{
				std::cout << "\n\tPrijava uspjesna ali Vam je nalog nazalost zatvoren, molimo obratite se zaposleniku.";
				std::cout << "\n\tZelite li odmah ponovo otvoriti svoj racun?\n";

				int answer;

				do
				{
					std::cout << "\n\tOdgovor (1 - Da, 0 - Ne): ";
					std::cin >> answer;

					while (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
						std::cout << "\n\tPogresan unos!";
						std::cout << "\n\tMolimo Vas da unesete ispravan naznaceni format unosa!";
						std::cout << "\n\t\tPonovni unos: ";
						std::cin >> answer;
					}

					if (answer != 1 && answer != 0) {
						std::cout << "\n\t[GRESKA] Molimo ponovite unos\n";
					}

					if (answer == 1) {
						users[userIndex]->setAccountOpen(true);
						std::cout << "\n\tUspjesno ste otvorili Vas racun. Hvala na povjerenju!\n";
						break;
					}
					else if (answer == 0)
					{
						std::cout << "\n\tNadamo se da cete u buducnosti ponovo odabrati nase usluge. \n\tHvala na povjerenju!\n";
						exit(0);
					}
				} while (answer != 1 and answer != 0);
			}
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
			std::cout << "\n\tPogresan unos!\n\tNemate preostalih pokusaja, nalog je trenutno blokiran zbog sigurnosti vlasnika.\n";
			exit(0);
		}
	}

	std::shared_ptr<User> currentUser;
	currentUser = users[userIndex];
	int option = 0;
	int money;

	std::ofstream log("logs.txt", std::ios::app);
	logUser(log, currentUser);

	while (true)
	{
		std::cout << "\n\n\tDobrodosli " << currentUser->getFirstName() << "!\n"
			<< "\n\n\tOpcije:"
			<< "\n\t\t1 - Depozit novac"
			<< "\n\t\t2 - Podigni novac"
			<< "\n\t\t3 - Prikazi stanje"
			<< "\n\t\t4 - Promjena passworda"
			<< "\n\t\t0 - Izlaz"
			<< "\n\n\t\tOpcija: ";

		std::cin >> option;
		option = inputCheck(option);

		if (option == 1)
		{
			std::cout << "\n\tMolimo unesite velicinu depozita: ";
			std::cin >> money;
			money = inputCheck(money);
			currentUser->setAccountBalance(currentUser->getAccountBalance() + money);
			std::cout << "\n\tDepozit uspjesno izvrsen.";
			std::cout << "\n\n\tHvala Vam na povjerenju!";
			printTransaction(log, currentUser, money);
		}
		else if (option == 2)
		{
			std::cout << "\n\tMolimo unesite velisinu isplate: ";
			std::cin >> money;
			money = inputCheck(money);

			if (currentUser->getAccountBalance() >= 0)
			{
				if (currentUser->getAccountBalance() - money < 0)
				{
					if (currentUser->getAccountBalance() - money < -currentUser->getAccountLimit())
					{
						std::cout << "\n\tNemate dovoljno novca na racunu cak i kada biste usli u minus!";
						std::cout << "\n\n\tStanje racuna: " << currentUser->getAccountBalance() << "KM";
						std::cout << "\n\n\tLimit racuna: " << currentUser->getAccountLimit() << "KM";
					}
					else
					{
						std::cout << "\n\tNemate dovoljno novca na racunu, da li zelite uci u minus [ 1 - DA | 0 - NE]: ";
						bool enterMinus;
						std::cin >> enterMinus;
						enterMinus = inputCheck(enterMinus);

						if (enterMinus)
						{
							completePayment(currentUser, money);
							printTransaction(log, currentUser, -money);
						}
						else
						{
							std::cout << "\n\tUplata nije izvrsena!";
						}
					}
				}
				else
				{
					completePayment(currentUser, money);
					printTransaction(log, currentUser, -money);
				}
			}
			else
			{
				if (currentUser->getAccountBalance() - money > -currentUser->getAccountLimit())
				{
					completePayment(currentUser, money);
					printTransaction(log, currentUser, -money);
				}
				else
				{
					std::cout << "\n\tNe možete uci dalje u minus!";
					std::cout << "\n\n\tStanje racuna: " << currentUser->getAccountBalance() << "KM";
					std::cout << "\n\n\tLimit racuna: " << currentUser->getAccountLimit() << "KM";
				}
			}
		}
		else if (option == 3)
		{
			std::cout << "\n\n\tStanje racuna: " << currentUser->getAccountBalance() << "KM";
			std::cout << "\n\n\tLimit racuna: " << currentUser->getAccountLimit() << "KM";
		}
		else if (option == 4)
		{
			numberOfTries = 3;

			while (true)
			{
				std::cout << "\n\n\tMolimo unesite trenutni password: ";
				std::cin >> password;

				numberOfTries--;

				encryptedPassword = encryptPassword(password);
				if (encryptedPassword == currentUser->getEncryptedPassword())
				{
					std::cout << "\n\tMolimo unesite novi password:";
					std::cin >> password;

					currentUser->setEncryptedPassword(encryptPassword(password));

					break;
				}
				else if (numberOfTries > 0)
				{
					std::cout << "\n\tPogresan unos!\n\tPreostalo pokusaja: " << numberOfTries;
				}
				else
				{
					std::cout << "\n\tPogresan unos!\n\tNemate preostalih pokusaja, nalog je trenutno blokiran zbog sigurnosti vlasnika.";
					exit(0);
				}
			}
		}
		else if (option == 0)
		{
			break;
		}
		else
		{
			std::cout << "\n\t\tPogresan unos!";
		}
		std::cout << "\n\n\t\t";
		pause();
	}
}