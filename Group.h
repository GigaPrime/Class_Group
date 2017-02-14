#ifndef __GROUP_H__
#define __GROUP_H__

#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

class Group
{
private:
	vector<Student> students;
	string groupName;
public:
	Group(Group&);
	Group(string);
	Group(vector<Student>, string);
	~Group();

	void addStudent(Student&);
	void removeStudent(Student&);
	int groupSize();
	vector<string> getSortedStudentsNames();
	Group operator=(Group&);
};

#endif // !__GROUP_H__

//1. ������� �������� � ������������� �� ���������
//2. ���������������� �������� ����� �������
//3. ������ �������� � ������ (� ������ ��� ������)
//4. ��������� ��������� ������
