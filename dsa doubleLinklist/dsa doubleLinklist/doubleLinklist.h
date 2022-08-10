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
	Node<T>* prev;

	Node(int inData, Node<T>* nPtr = NULL, Node<T>* pPtr = NULL)
	{
		data = inData;
		next = nPtr;
		prev = pPtr;
	}
};
template<class T>
class DLinkedList
{
	Node<T>* head;
	Node<T>* tail;
public:
	DLinkedList() :head(NULL), tail(NULL)
	{

	}
	DLinkedList(const DLinkedList& obj);
	bool isEmpty();
	void insertAtTail(T value);
	void insertAtHead(T value);
	Node<T>* getHead();
	Node<T> * getTail();
	void printList();
	bool deleteAtHead();
	bool deleteAtTail();
	Node<T>* search(T key);
	bool insertAfter(T val, T key);
	bool deleteAfter(T key);
	void setHead(Node<T>* HEAD);
    void setTail(Node<T> * TAIL);
	Node<T>* getNode(int n);
	int getLength();
	~DLinkedList()
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

