#pragma once
#include <cstring>
#include <vector>

struct Person
{
	int idNumber;
	char personName[64];

	Person()
	{
		idNumber = 0;
		strcpy(personName, "");
	}
};

struct CourseInstructor : public Person
{

};

struct Student : public Person
{
	 
};