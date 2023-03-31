#pragma once
#include<iostream>
#include<stdexcept>
template<typename T>
class ListNode
{
public:
	T data;
	ListNode* next;
	ListNode(const T& data,ListNode* next = nullptr):data(data),next(next){}
	~ListNode(){}
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
		ListNode<T>* current = head;
		while (current) {
			ListNode<T>* next = current->next;
			delete current;
			current = next;
		}
	}
	void push_front(const T& data)
	{
		head = new ListNode<T>(data, head);
	}
	class Iterator 
	{
	private:
		ListNode<T>* current;
	public:
		Iterator (ListNode<T>* start):current(start){}
		T& operator*() 
		{
			if (!current)
			{
				throw std::out_of_range("Iterator out of range");
			}
			return current->data;
		}
		Iterator& operator++() 
		{
			if (current) {
				current = current->next;
			}
			return *this;
		}
		bool operator!=(const Iterator& other) const 
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
	LinkedList<int>list;
	int arr[] = { 1,2,3,4,5 };
	list.push_front(5);
	list.push_front(4);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);
	for (auto it = list.begin(); it != list.end(); ++it) 
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << "--------------------" << std::endl;
	std::cout << "LinkedList<double> : " << std::endl;
	LinkedList<double>list_double;
	list_double.push_front(25.1);
	list_double.push_front(34.1);
	list_double.push_front(53.53);
	list_double.push_front(123.14);
	list_double.push_front(1235.21);
	for (auto it = list_double.begin(); it != list_double.end(); ++it)
	{
		std::cout << *it << " ";
	}
}