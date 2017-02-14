#include <iostream>
#include <string>
#include "student.h"

Student::Student() 
{
	name = new char;
	surname = new char;
	group = new char;
	
	strcpy(name, "newName");
	strcpy(surname, "newSurname");
	strcpy(group, "newGroup");

	progMark = 0;
	adminMark = 0;
	designMark = 0;
}

Student::Student(char *n, char *s, char *g, int pMark, int aMark, int dMark) 
{
	name = new char[strlen(n) + 1];
	surname = new char[strlen(s) + 1];
	group = new char[strlen(g) + 1];

	strcpy(name, n);
	strcpy(surname, s);
	strcpy(group, g);

	progMark = pMark;
	adminMark = aMark;
	designMark = dMark;
}

Student::Student(Student& student)
{
	name = new char[strlen(student.name) + 1];
	surname = new char[strlen(student.surname) + 1];
	group = new char[strlen(student.group) + 1];

	strcpy(name, student.name);
	strcpy(surname, student.surname);
	strcpy(group, student.group);
	
	progMark = student.progMark;
	adminMark = student.adminMark;

	std::cout << "Copy constructor call" << std::endl << std::endl;
}

Student::~Student()
{
	delete[] name;
	delete[] surname;
	delete[] group;
}

void Student::setName(char *n) 
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void Student::setSurname(char *s) 
{
	surname = new char[strlen(s) + 1];
	strcpy(surname, s);
}

void Student::setGroup(char *g) 
{
	group = new char[strlen(g) + 1];
	strcpy(group, g);
}

void Student::setProgMark(int pMark)
{
	progMark = pMark;
}

void Student::setAdminMark(int aMark)
{
	 adminMark = aMark;
}

void Student::setDesignMark(int dMark)
{
	 designMark = dMark;
}

char Student::getName()
{
	return *name;
}

char Student::getSurname()
{
	return *surname;
}

char Student::getGroup()
{
	return *group;
}

int Student::getProgMark()
{
	return progMark;
}

int Student::getAdminMark()
{
	return adminMark;
}

int Student::getDesignMark()
{
	return designMark;
}

void Student::print()
{
	std::cout << "\tStudent's data" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "name:\t\t" << name << std::endl;
	std::cout << "surname:\t" << surname << std::endl;
	std::cout << "group #:\t" << group << std::endl;
	std::cout << "programming:\t" << getProgMark() << std::endl;
	std::cout << "administation:\t" << getAdminMark() << std::endl;
	std::cout << "design:\t\t" << getDesignMark() << std::endl << std::endl;
}

void Student::input()
{
	std::cout << "\tStudent's input" << std::endl;
	std::cout << "--------------------------" << std::endl;

	char *tmpStudent = new char[10];
	
	std::cout << "name:\t\t";
	std::cin >> tmpStudent;
	setName(tmpStudent);

	std::cout << "surname:\t";
	std::cin >> tmpStudent;
	setSurname(tmpStudent);

	std::cout << "group #:\t";
	std::cin >> tmpStudent;
	setGroup(tmpStudent);
	
	int tmpMark;

	std::cout << "programming:\t";
	std::cin >> tmpMark;
	setProgMark(tmpMark);
	
	std::cout << "administration:\t";
	std::cin >> tmpMark;
	setAdminMark(tmpMark);

	std::cout << "design:\t\t";
	std::cin >> tmpMark;
	setDesignMark(tmpMark);

	std::cout << std::endl;
}

void Student::save(std::ostream& stream)
{
	int nameLenght = strlen(name);
	int surnameLenght = strlen(surname);
	int groupLenght = strlen(group);

	stream.write((char*)&nameLenght, sizeof(nameLenght));
	stream.write(name, nameLenght);

	stream.write((char*)&surnameLenght, sizeof(surnameLenght));
	stream.write(surname, surnameLenght);

	stream.write((char*)&groupLenght, sizeof(groupLenght));
	stream.write(group, groupLenght);

	stream.write((char*)&progMark, sizeof(progMark));
	stream.write((char*)&adminMark, sizeof(adminMark));
	stream.write((char*)&designMark, sizeof(designMark));
}

void Student::load(std::ifstream &stream)
{
	int nameLenght = 0;
	int surnameLenght = 0;
	int groupLenght = 0;

	stream.read((char*)&nameLenght, sizeof(nameLenght));
	if (name != nullptr)
		delete[] name;
	name = new char[nameLenght + 1];
	stream.read(name, nameLenght);
	name[nameLenght] = '\0';

	stream.read((char*)&surnameLenght, sizeof(surnameLenght));
	if (surname != nullptr)
		delete[] surname;
	surname = new char[surnameLenght + 1];
	stream.read(surname, surnameLenght);
	surname[surnameLenght] = '\0';

	stream.read((char*)&groupLenght, sizeof(groupLenght));
	if (group != nullptr)
		delete[] group;
	group = new char[groupLenght + 1];
	stream.read(group, groupLenght);
	group[groupLenght] = '\0';

	stream.read((char*)&progMark, sizeof(progMark));
	stream.read((char*)&adminMark, sizeof(adminMark));
	stream.read((char*)&designMark, sizeof(designMark));
}

bool Student::operator==(Student& student)
{
	 return (strcmp(name, student.name) == 0) && 
			(strcmp(surname, student.surname) == 0) &&
			(strcmp(group, student.group) == 0) &&
			progMark == student.progMark &&
			adminMark == student.adminMark &&
			designMark == student.designMark;
}

Student Student::operator=(Student& student)
{
	if (this == &student)
		return *this;
	if (student.name != nullptr)
	{
		name = new char[strlen(student.name) + 1];
		strcpy(name, student.name);
	}
	else
		name = nullptr;

	if (student.surname != nullptr)
	{
		surname = new char[strlen(student.surname) + 1];
		strcpy(surname, student.surname);
	}
	else
		surname = nullptr;

	if (student.group != nullptr)
	{
		group = new char[strlen(student.group) + 1];
		strcpy(group, student.group);
	}
	else
		group = nullptr;
	
	progMark = student.progMark;
	adminMark = student.adminMark;
	designMark = student.designMark;

	return student;
}
