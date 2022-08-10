#include <iostream>
#include <string>
#include"Doublelinklist.h"
#include"Doublelinklist.cpp"
using namespace std;

int main()
{
	DLinkedList<int> list;
	int inputVal;
	int key;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a value to insert at head: ";
		cin >> inputVal;
		list.insertAtHead(inputVal);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter a value to insert at tail: ";
		cin >> inputVal;
		list.insertAtTail(inputVal);
	}  
	list.printList();
	if (list.deleteAtHead())
	{
		cout << "Value deleted at head successfully" << endl;
	}
	else
	{
		cout << "Value not deleted at head" << endl;
	}
	list.printList();
	if (list.deleteAtTail())
	{
		cout << "Value deleted at tail successfully" << endl;
	}
	else
	{
		cout << "Value not deleted at tail" << endl;
	}
	list.printList();
	cout << "Enter value you want to place at head : ";
	cin >> key;
	Node<int>* setHead = new Node<int>(key);
	list.setHead(setHead);
	list.printList();   
	cout << "Enter value you want to place at tail : ";
	cin >> key;
	Node<int>* setTAIL = new Node<int>(key);
	list.setTail(setTAIL);
	list.printList();
	cout << "Enter the value you want to find in the list : ";
	cin >> key;
	cout << "Enter the value you want to insert after found value : ";
	cin >> inputVal;
	if (list.insertAfter(inputVal, key))
	{
		cout << "Value enter successfully" << endl;
	}
	else
	{
		cout << "Input not found" << endl;
	}
	list.printList();  
	cout << "Enter the value you want to delete after : ";
	cin >> inputVal;
	if (list.deleteAfter(inputVal))
	{
		cout << "Value delete after key successfully" << endl;
	}
	else
	{
		cout << " key not found for value deleted after key" << endl;
	}
	list.printList();
	cout << "Length of list is = " << list.getLength() << endl;
	cout << " head = " <<  list.getHead() << endl;
	cout << "tail  = " << list.getTail() << endl;

}