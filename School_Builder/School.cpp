#define _CRT_SECURE_NO_WARNINGS
#include "School.h"
#include <iostream>
#include "Helper.h"
#include <cstdlib>
#include <ctime>


School::School()
{
	schoolBuilder = new std::map<int, Course>();
	FileHandler::ReadCourses(coursesBIN, *schoolBuilder);
	FileHandler::ReadRosters(rostersBIN, *schoolBuilder);
}

School::School(const School& other)
{
	schoolBuilder = new std::map<int, Course>(*other.schoolBuilder);
	coursesBIN = other.coursesBIN;
	rostersBIN = other.rostersBIN;
}

School& School::operator=(const School& other)
{
	if (this != &other)
	{
		delete schoolBuilder;
		schoolBuilder = new std::map<int, Course>(*other.schoolBuilder);
		coursesBIN = other.coursesBIN;
		rostersBIN = other.rostersBIN;
	}
	return *this;
}

School::~School()
{
	delete schoolBuilder;
}

Course* School::GetCourse(int key)
{
	if (schoolBuilder->find(key) != schoolBuilder->end())
	{
		return &schoolBuilder->at(key);
	}
	return nullptr;
}

std::map<int, Course>* School::GetSchool()
{
	return schoolBuilder;
}

std::string School::GetCourseFileBIN() const
{
	return coursesBIN;
}

std::string School::GetRosterFileBIN() const
{
	return rostersBIN;
}

void School::PrintSchool()
{
	for (const auto& entry : *schoolBuilder)
	{
		const Course& course = entry.second;
		std::cout << "Course ID: " << course.GetCourseId() << "\n";
		std::cout << "Course Name: " << course.GetCourseName() << "\n";
		std::cout << "Instructor ID: " << course.GetInstructor().courseId << "\n";
		std::cout << "Instructor Name: " << course.GetInstructor().courseName << "\n";
		std::cout << "Students:\n";
		for (const auto& student : course.GetStudents())
		{
			std::cout << "\tID: " << student.studentId << " | Name: " << student.studentName << "\n";
		}
		std::cout << "--------------------------\n";
	}
}

void School::AddStudent()
{
	std::cout << "Available Courses:\n";
	for (auto it = schoolBuilder->begin(); it != schoolBuilder->end(); ++it)
	{
		std::cout << "Course ID: " << it->first << " | Name: " << it->second.GetCourseName() << "\n";
	}

	int selectedCourseId;
	bool validCourse = false;

	while (!validCourse)
	{
		std::cout << "Enter a Course ID: ";
		std::cin >> selectedCourseId;

		if (schoolBuilder->find(selectedCourseId) != schoolBuilder->end())
		{
			validCourse = true;
		}
		else
		{
			std::cout << "Invalid Course ID. Please try again.\n";
		}
	}
	std::cin.ignore();

	std::string studentName;
	std::cout << "Enter the student's name: ";
	std::getline(std::cin, studentName);

	int studentId = 1000 + (rand() % 9000);

	Student newStudent;
	newStudent.studentId = studentId;
	newStudent.studentName = studentName;

	schoolBuilder->at(selectedCourseId).AddStudent(newStudent);

	std::cout << "\nStudent added successfully!\n";
}
