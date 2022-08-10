#pragma once
#include <iostream>
using namespace std;

class node
{
public:
	int data = 0;
	node* npx = nullptr;
};

node* XOR(node* a, node* b)
{
	return (node*)((unsigned int)(a) ^ (unsigned int)(b));
}

class LinkedList
{
private:
	node* head, * tail;
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	void insertAtHead(int val);
	void insertAtTail(int val);
	bool search(int key);
	int removeAtHead();
	int removeAtTail();
	void print();
};

#include<iostream>
using namespace std;
#include"xorLinklist.h"
void LinkedList::insertAtHead(int val)
{
	//storing value in temporary node
	node* temp = new node;
	temp->data = val;
	//if no node found  than head and tail will be same 
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		//set npx of temp as XOR of head and Null (Null is before head)
		temp->npx = XOR(NULL, head);
		//settting npx of head as XOR of (temp and npx of head)
		// as current head is going  between temp and node next to head
		head->npx = XOR(temp, head->npx);
		//setting head to temp
		head = temp;
	}
}

void LinkedList::insertAtTail(int val)
{
	//storing value in temporary node
	node* temp = new node;
	temp->data = val;
	//if no node found  than head and tail will be same 
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		// setting npx of temp as XOR of (Null(no node exist after) and tail)
		temp->npx = XOR(NULL, tail);
		//setting npx of tail as XOR of (temp and npx of tail)
		// as current tail is going between (temp and node before tail)
		tail->npx = XOR(temp, tail->npx);
		//setting tail to temp
		tail = temp;
	}
}

void LinkedList::print()
{
	node* prev = NULL;
	node* next = NULL;
	node* curr = head;
	//till very last node
	while (curr != NULL)
	{
		//print data
		cout << curr->data << " ";
		//next node will be XOR of (prev node and curr npx)
		next = XOR(prev, curr->npx);
		//current node is now previous one
		prev = curr;
		//next node becomes current node
		curr = next;
	}

	cout << endl;
}

bool LinkedList::search(int key)
{
	//making next and previous pointers at start pointing to NULL
	node* prev = NULL;
	node* next = NULL;
	//current pointer is poiting towards head
	node* curr = head;
	//search till last node
	while (curr != NULL)
	{
		//if key matches the data
		if (curr->data == key)
		{
			//found==true
			return true;
		}
		//next node will be XOR ( prev node address and current npx)
		next = XOR(prev, curr->npx);
		//current node is now previous one
		prev = curr;
		//next node becomes current node
		curr = next;
	}
	//if not false is returned
	return false;
}
int LinkedList::removeAtHead()
{
	//storing data at head of XOR List
	int value = head->data;
	//search for the next node of head by taking XOR Of Null witg npx of Head
	node* next = XOR(NULL, head->npx);
	//setting  npx of next with adress of node next to head
	next->npx = XOR(next->npx, head);
	//next node now contains head
	head = next;
	//return value
	return value;

}

int LinkedList::removeAtTail()
{
	//storing data at tail of XOR List
	int value = tail->data;
	//search for the pervious node of tail by taking XOR Of Null witg npx of Tail
	node* prev = XOR(NULL, tail->npx);
	//setting  tail to previous pointer 
	prev->npx = XOR(prev->npx, tail);
	//After xor previous is now set to tail
	tail = prev;
	//returning the value
	return value;

}
