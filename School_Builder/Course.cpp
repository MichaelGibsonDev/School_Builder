#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include "Structs.h"

class Course
{
private:
	char courseName[64];
	int courseId;
	CourseInstructor instructor;
	std::vector<Student> _students;

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

	const std::vector<Student>& GetStudents() const { return _students; }
	void SetStudents(const std::vector<Student>& newStudents) { _students = newStudents; }

	void AddStudent(const Student& s)
	{
		_students.push_back(s);
	}

	void SetCourseId(int id)
	{
		courseId = id;
	}

	int GetCourseId() const
	{
		return courseId;
	}
};