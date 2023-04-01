#pragma once
#include<iostream>
template <typename T>
T searchMinCount(T array[], size_t size) {
	T min_value = array[0];
	int min_count = 1;
	for (size_t i = 1; i < size; i++) {
		if (array[i] < min_value) {
			min_value = array[i];
			min_count = 1;
		}
		else if (array[i] == min_value) {
			min_count++;
		}
	}
	std::cout << "Min value: " << min_value << ", count: " << min_count << std::endl;
	return min_value;
}
template<>   char* searchMinCount(char* array[], size_t size)
{
	char* min = (char*)array[0];
	int count = 1;
	for (size_t i = 1; i < size; i++) {
		if (std::strcmp(array[i], min) < 0) {
			min = (char*)array[i];
			count = 1;
		}
		else if (std::strcmp(array[i], min) == 0) {
			count++;
		}
	}
	std::cout << "Min value: " << min << ", count: " << count << std::endl;
	return min;
}
void Task1() {
	int arr[] = { 3, 5, 1, 3, 2, 5 , 1, 3, 2, 1 };
	std::cout << "--------------------"<<std::endl;
	std::cout << "Test tameplate" << std::endl;
	std::cout << "[";
	for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
		std::cout << " " << arr[i];
	}
	std::cout << " ]" << std::endl;
	int min = searchMinCount(arr, sizeof(arr) / sizeof(int));
	std::cout << "--------------------" << std::endl;
	std::cout << "Test specification tameplate <char*>" << std::endl;
	std::cout << "[";
	char* array[] = { (char*)"boo",(char*)"foo",(char*)"foo",(char*)"boo",(char*)"foo" };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		std::cout << " " << array[i];
	}
	std::cout << " ]" << std::endl;
	char* ptr = searchMinCount<char*>(array, 5);
	std::cout << "---------------------" << std::endl;
	std::cout << "End test!!!" << std::endl;
}