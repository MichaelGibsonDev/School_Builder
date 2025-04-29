#pragma once
#include <string>

namespace Helper
{
	//Checking if this is a valid integer
	static bool IsInteger(const char* input);
	//Print integer as a binary
	static void PrintIntegerBinary(int* num);
	//To bubblesort the function
	static void BubbleSort(int* arr, int size);
	//Clears leftover junk input
	static void ClearInputBuffer();
	//Returns a random number
	static int RandomNumberGenerator(int min = 1, int max = 100);
	
	int GetMenuChoice(const std::string& prompt);
}