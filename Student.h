#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <fstream>

class Student
{
private:
	char* name;
	char* surname;
	char* group;
	int progMark;
	int adminMark;
	int designMark;

public:
	Student();
	Student(char *n, char *s, char *g, int pMark, int aMark, int dMark);
	Student(Student& student);

	~Student();

	void setName(char *n);
	void setSurname(char *s);
	void setGroup(char *g);
	void setProgMark(int pMark);
	void setAdminMark(int aMark);
	void setDesignMark(int dMark);

	char getName();
	char getSurname();
	char getGroup();
	int getProgMark();
	int getAdminMark();
	int getDesignMark();

	void print();
	void input();

	void save(std::ostream& stream);
	void load(std::ifstream& stream);

	bool operator==(Student&);
	Student operator=(Student&);
};
#endif // !__STUDENT_H__
