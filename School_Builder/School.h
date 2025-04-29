#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <map>
#include "Course.h"
#include "FileHandler.h"


class School
{
private:
	std::string coursesBIN = "SchoolBuilderFile_Courses.bin";
	std::string rostersBIN = "SchoolBuilderFile_Rosters.bin";
	std::map<int, Course>* schoolBuilder;

public:
	School();
	School(const School& other);
	School& operator=(const School& other);
	~School();

	Course* GetCourse(int key);
	std::map<int, Course>* GetSchool();
	std::string GetCourseFileBIN() const;
	std::string GetRosterFileBIN() const;

	void PrintSchool();

	void AddStudent();
};


