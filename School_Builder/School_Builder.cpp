// School_Builder.cpp : This file contains the 'main' function. Program execution begins and ends there.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "School.h"
#include <iostream>
#include "Helper.h"
#include "Structs.h"

int main()
{
    std::cout << "School Builder Program Started." << std::endl; 

    School mySchool;

    mySchool.PrintSchool();

    mySchool.AddStudent();

    mySchool.PrintSchool();

    return 0;
}
