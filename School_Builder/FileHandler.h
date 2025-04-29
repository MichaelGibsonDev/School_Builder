#pragma once
#include <fstream>
#include <map>
#include <string>
#include "Helper.h"
#include "Structs.h"
#include "Course.h"

namespace FileHandler
{
	static void ReadCourses(const std::string& filename, std::map<int, Course>& school)
	{
		std::ifstream input(filename, std::ios::binary);
		if (!input.is_open())
		{
			std::cout << "Could not open the courses file.\n";
			return;
		}

		while (input.peek() != EOF)
		{
			int courseId = 0;
			char instructorName[64] = {};
			int instructorId = 0;
			char courseName[64] = {};

			input.read((char*)&courseId, sizeof(courseId));
			input.read((char*)&instructorName, sizeof(instructorName));
			input.read((char*)&instructorId, sizeof(instructorId));
			input.read((char*)&courseName, sizeof(courseName));

			CourseInstructor tempInstructor;
			tempInstructor.courseId = instructorId;
			tempInstructor.courseName = instructorName; 

			Course tempCourse;
			tempCourse.SetCourseId(courseId);
			tempCourse.SetInstructor(tempInstructor);
			tempCourse.SetCourseName(courseName);

			school[courseId] = tempCourse;
		}

		input.close();
	}

	static void ReadRosters(const std::string& filename, std::map<int, Course>& school)
	{
		std::ifstream input(filename, std::ios::binary);
		if (!input.is_open())
		{
			std::cout << "Could not open the rosters file.\n";
			return;
		}

		while (input.peek() != EOF)
		{
			int courseId = 0;
			int studentId = 0;
			char studentName[64] = {};

			input.read((char*)&courseId, sizeof(courseId));
			input.read((char*)&studentId, sizeof(studentId));
			input.read((char*)&studentName, sizeof(studentName));

			Student tempStudent;
			tempStudent.studentId = studentId;
			tempStudent.studentName = studentName; 

			if (school.find(courseId) != school.end())
			{
				school[courseId].AddStudent(tempStudent);
			}
		}

		input.close();
	}
}
