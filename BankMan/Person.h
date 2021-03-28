#pragma once

class Person
{
private:
	std::string jmbg;

public:
	std::string firstName, lastName;
	int age;
	bool gender;

	Person() :
		jmbg(""), firstName(""), lastName(""), age(0), gender(0) {};
	Person(std::string jmbg, std::string firstName, std::string lastName, int age, bool gender) :
		jmbg(jmbg), firstName(firstName), lastName(lastName), age(age), gender(gender) {};

	void setJMBG(std::string jmbg) { this->jmbg = jmbg; }
	void setFirstName(std::string firstName) { this->firstName = firstName; }
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setAge(int age) { this->age = age; }
	void setGender(bool gender) { this->gender = gender; }

	std::string getJMBG() { return jmbg; }
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	int getAge() { return age; }
	bool getGender() { return gender; }

	virtual bool isAdmin()
	{
		return false;
	}

	~Person() {};
};

template <class T>
T inputCheck(T a)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\n\tPogresan unos!";
		std::cout << "\n\tMolimo Vas da unesete ispravan naznaceni format unosa!";
		std::cout << "\n\t\tPonovni unos: ";
		std::cin >> a;
	}

	return a;
}

unsigned long long encryptPassword(std::string password)
{
	int encrypted = 0;

	for (int i = 0; i < password.size(); i++)
	{
		encrypted += password[i] * 1234 + 53123;
	}

	return encrypted;
}

void pause()
{
	std::cout << "\n\n\t";
	system("pause");
	system("cls");
}