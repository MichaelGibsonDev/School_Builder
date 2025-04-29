// School_Builder.cpp : This file contains the 'main' function. Program execution begins and ends there.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "School.h"
#include <iostream>
#include "Helper.h"
#include "Structs.h"

int main()
{

    School* mySchool = new School();
    int choice = 0;

    do
    {
        std::cout << "\n===== School Builder Menu =====\n";
        std::cout << "1. View the whole School\n";
        std::cout << "2. Add a Student to a Course\n";
        std::cout << "3. Write Rosters to File\n";
        std::cout << "4. Write Courses to File\n";
        std::cout << "5. Exit Program\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            mySchool->PrintSchool();
            break;

        case 2:
            mySchool->AddStudent();
            break;

        case 3:
            std::cout << "Rosters file overwritten (function will be added in Part 5).\n";
            break;

        case 4:
            std::cout << "Courses are overwritten (function will be added in Part 5).\n";
            break;

        case 5:
            std::cout << "Exiting Program...\n";
            break;

        default:
            std::cout << "Invalid chocie. Please select again.\n";
            break;
        }
    } while (choice != 5);

    delete mySchool;
    mySchool = nullptr;

    return 0;
}
