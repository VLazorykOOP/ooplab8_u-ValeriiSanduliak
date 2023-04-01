#pragma once
#include<iostream>
#include<stdexcept>
template<typename T>
class ListNode
{
public:
	T data;
	ListNode* next;
	ListNode(T data = T(), ListNode* next = nullptr) : data(data), next(next) {}
	~ListNode() {}
};
template<typename T>
class LinkedList
{
private:
	ListNode<T>* head;
public:
	LinkedList() :head(nullptr){}
	~LinkedList() 
	{
		while (head!=nullptr) {
			ListNode<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void push_back(T data)
	{
			if (head == nullptr) {
				head = new ListNode<T>(data);
			}
			else {
				ListNode<T>* current = head;
				while (current->next != nullptr) {
					current = current->next;
				}
				current->next = new ListNode<T>(data);
			}
	}	
	class Iterator {
	private:
		ListNode<T>* current;
	public:
		Iterator(ListNode<T>* start) 
		{
			current = start;
		}
		T& operator*()
		{
			if (current == nullptr) {
				throw std::out_of_range("Iterator out of range");
			}
			return current->data;
		}
		Iterator& operator++()
		{
			if (current == nullptr) {
				throw std::out_of_range("Iterator out of range");
			}
			current = current->next;
			return *this;
		}
		bool operator !=(const Iterator& other)
		{
			return current != other.current;
		}
	};
	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}
};

void Task4()
{
	std::cout << "--------------------" << std::endl;
	std::cout << "Test linked list:" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "LinkedList<int> : " << std::endl;
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it <<" ";
	}
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "LinkedList<double> : " << std::endl;
	LinkedList<double> list_double;
	list_double.push_back(25.1);
	list_double.push_back(34.1);
	list_double.push_back(53.53);
	list_double.push_back(123.14);
	list_double.push_back(1235.21);
	for (auto it = list_double.begin(); it != list_double.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "LinkedList<char> : " << std::endl;
	LinkedList<char> list_char;
	list_char.push_back('a');
	list_char.push_back('p');
	list_char.push_back('p');
	list_char.push_back('l');
	list_char.push_back('e');
	for (auto it = list_char.begin(); it != list_char.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout<<std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "End test!!!" << std::endl;
}
