#include <iostream>
#include <conio.h>
#include "Group.h"
#include "Student.h"

using namespace std;

Group::Group(Group& group)
{
	students = group.students;
	groupName = group.groupName;
}

Group::Group(string groupName) 
{
	this->groupName = "BNU";
}

Group::Group(vector<Student> students, string groupName)
{
	vector<Student>::iterator i;
	for (i = students.begin(); i < students.end(); i++)
	{
		students.push_back(*i);
	}
	this->groupName = "BNU";
}

void Group::addStudent(Student& student)
{
	students.push_back(student);
}

Group::~Group() {}

void Group::removeStudent(Student& student)
{
	vector<Student>::iterator i;
	for (i = students.begin(); i < students.end(); i++)
	{
		if (student == *i)
		{
			students.erase(i);
		}
	}
}

int Group::groupSize()
{
	return students.size();
}

vector<string> Group::getSortedStudentsNames()
{
	
}

Group Group::operator=(Group& group)
{
	students = group.students;
}
