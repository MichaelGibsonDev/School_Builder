#pragma once
#include <iostream>
#include <vector>
#include "Structs.h"


class Course
{
private:
	char courseName[64];
	int courseId;
	CourseInstructor instructor;
	std::vector<Student> students;

public:
	Course()
	{
		courseId = 0;
		strcpy(courseName, "");
	}

	const char* GetCourseName() const { return courseName; }
	void SetCourseName(const char* name)
	{
		strncpy(courseName, name, 63);
		courseName[63] = '\0';
	}

	const CourseInstructor& GetInstructor() const { return instructor; }
	void SetInstructor(const CourseInstructor& newInstructor) { instructor = newInstructor; }

	const std::vector<Student>& GetStudents() const { return students; }
	void SetStudents(const std::vector<Student>& newStudents) { students = newStudents; } 
};