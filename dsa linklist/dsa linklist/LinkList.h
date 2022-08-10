#pragma once
#include <iostream>
#include <string>
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
	void keyPresent(T value);
	void keyPresentPart2(T value);
	LinkedList(const LinkedList& obj);
	bool isEmpty();
	void insertAtTail(T value);
	void insertAtHead(T value);
	void printList();
	bool insertAfter(T val, T key);
	bool insertBefore(T val, T key);
	Node<T>* search(T key);
	bool deleteAtHead();
	bool deleteAtTail();
	bool deleteAfter(T key);
	bool deleteBefore(T key);
	Node<T>* getNode(int n);
	int getLength();
	Node<T>* SEARCH(T x);
	~LinkedList()
	{
		Node<T>* temp = head;
		while (temp)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
	void reverse();
};

