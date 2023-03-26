#pragma once
#include<iostream>
#include<algorithm>
template<typename T>
int binarySearch(T arr[],size_t n,T x) {
	int left = 0;
	int right = n - 1;
	while (left <= right) 
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) 
		{
			return mid;
		}
		else if(arr[mid]<x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
template<>  
int binarySearch<char*>(char* arr[], size_t n, char* x) {
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		int cmp = strcmp(arr[mid], x);
		if (cmp == 0)
			return mid;

		if (cmp < 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
template<typename T>
void bubble_sort(T arr[], size_t n) 
{
	for (size_t i = 0; i < n - 1; i++) 
	{
		for (size_t j = 0; j < n - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
template<>
void bubble_sort<char*>(char* arr[], size_t n) {
	for (size_t i = 0; i < n - 1; i++) 
	{
		for (size_t j = 0; j < n - i - 1; j++) 
		{
			if (strcmp(arr[j], arr[j + 1]) > 0) 
			{
				char* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void Task2()
{
	std::cout << "--------------------" << std::endl;
	std::cout << "Test tameplate binary_search: " << std::endl;
	int arr[] = {4,2,5,1,3};
	std::cout << "Arr before sort: " << std::endl;
	for (const auto& s : arr) 
	{
		std::cout << s<< " ";
	}
	bubble_sort(arr, sizeof(arr) / sizeof(int));
	std::cout << std::endl << "Arr after sort: " << std::endl;
	for (const auto& s : arr) 
	{
		std::cout << s << " ";
	}
	std::cout << std::endl << "---------------------" << std::endl;
	int searchV = 5;
	int intIndex = binarySearch(arr, sizeof(arr) / sizeof(int), searchV);
	if (intIndex == -1) 
	{
		std::cout << "Element[ " << searchV << " ] not found\n";
	}
	else 
	{
		std::cout << "Element [ " << searchV << " ] was found at position: " << intIndex << "\n";
	}
	std::cout << "--------------------" << std::endl;
	std::cout << "Test specification tameplate <char*>: " << std::endl;
	char* char_arr[] = { (char*)"banana",(char*)"apple", (char*)"cherry", (char*)"grape", (char*)"orange"};
	size_t ch_size = sizeof(char_arr) / sizeof(char_arr[0]);
	std::cout << "Arr before sort: " << std::endl;
	for(const auto& c : char_arr)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl << "Arr after sort: " << std::endl;
	bubble_sort<char*>(char_arr, ch_size);
	char* x1 = (char*)"grape";
	for (const auto& c : char_arr) {
		std::cout << c << " ";
	}
	std::cout << std::endl << "---------------------";
	int charIndex1 = binarySearch<char*>(char_arr,ch_size, x1);
	if (charIndex1 == -1)
	{
		std::cout << "Element not found\n";
	}
	else
	{
		std::cout << std::endl << "Element [ " << x1 << " ] was found at position : " << charIndex1 << "\n";
	}
	std::cout << "---------------------" << std::endl;
	char* x2 = (char*)"saff";
	int charIndex2 = binarySearch<char*>(char_arr, ch_size, x2);
	if (charIndex2 == -1)
	{
		std::cout << "Element[ " << x2 << " ] not found\n";
	}
	else
	{
		std::cout << std::endl << "Element [ " << x2 << " ] was found at position : " << charIndex2 << "\n";
	}
	std::cout << "---------------------" << std::endl;
}
