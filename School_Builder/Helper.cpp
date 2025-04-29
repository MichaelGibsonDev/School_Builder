#include "Helper.h"
#include <iostream>

int GetMenuChoice(const std::string& prompt)
{
    int choice;
    while (true)
    {
        std::cout << prompt;
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Try again.\n";
        }
        else
        {
            return choice;
        }
    }
}