#include <iostream>
#include <string>
#include "House.hpp"

class Student {

private:

	size_t id;
	static size_t studentsNumber;
	std::string name;
	static std::string group;
	static const time_t maxAge{ 55 }; //Константа требует инициализации внутри класса сразу же.
	time_t age;

public:

	Student() : Student("", 0) {}
	Student(std::string name, time_t age){
		this->name = name;
		setAge(age);
		id = ++studentsNumber;
	}
	Student(const Student& other) : Student(other.name, other.age) {}

	std::string getName() const { return name; }
	void setName(std::string name) { this->name = name; }

	static std::string getGroup() { return group; }
	static void setGroup(std::string group) { Student::group = group; }

	time_t getAge() const { return age; }
	void setAge(time_t age) {
		if (age >= 0 && age <= maxAge)
			this->age = age;
		else
			this->age = 0;
	}

	size_t getId() const { return id; }
	static size_t getStudentNumber() { return studentsNumber; }

};

std::string Student::group = "BV311"; //Объявление статического поля вне класса
size_t Student::studentsNumber{};

int main() {
	setlocale(LC_ALL, "Russian");

	//std::cout << Student::group << std::endl;

	//Модификации членов классов

	Student s1("Dabulla Chada", 33), s2("Tommy Angelo", 67);

	std::cout << s1.getGroup() << std::endl;
	std::cout << s2.getGroup() << std::endl;

	Student::setGroup("VBV311");

	std::cout << s1.getGroup() << std::endl;
	std::cout << Student::getGroup() << std::endl;

	std::cout << s1.getAge() << std::endl;
	std::cout << s2.getAge() << std::endl;

	std::cout << s1.getName() << std::endl;

	const Student s3("Has Mura Kar", 11);

	std::cout << s3.getName() << std::endl;
	s3.setGroup("BV311");
	std::cout << s3.getGroup() << std::endl;
	std::cout << s3.getId() << std::endl;

	House h1("WCHada Street", 57, 2);
	h1.appFlat(1, 1);
	h1.appFlat(2, 4);
	h1.printFlat(0);
	h1.printFlat(1);
	
	return 0;
}