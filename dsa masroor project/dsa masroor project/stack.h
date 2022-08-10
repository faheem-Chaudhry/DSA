#pragma once
//bsef19m013
//Osama Sultan
#pragma once
#include<iostream>
using namespace std;
template<class T>
//class LinkedList;
class Node
{
public:
	T data;
	Node<T>* next;

	Node(int inData, Node<T>* nPtr = NULL)
	{
		data = inData;
		next = nPtr;
	}
};
template<class T>
class LinkedList
{
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList() :head(NULL), tail(NULL)
	{

	}
	bool isEmpty();
	void insertAtTail(T value);
	void insertAtHead(T value);
	void printList();
	bool deleteAtHead();
	bool deleteAtTail();
	T getHead();
	T getTail();
	int getLength();
	void deleteNodes();         //Task 4
	  
	~LinkedList()                 //Task 5
	{
		Node<T>* temp = head;
		while (temp)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};