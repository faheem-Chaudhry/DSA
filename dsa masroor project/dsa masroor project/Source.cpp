//bsef19m013
//Osama Sultan
#include<iostream>
#include"stack.h"
#include"stack.cpp"
using namespace std;
int main()
{
	LinkedList<int> list;
	int inputVal;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a value to insert at head: ";
		cin >> inputVal;
		list.insertAtHead(inputVal);
	}
	list.printList();

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter a value to insert at tail: ";
		cin >> inputVal;
		list.insertAtTail(inputVal);
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
	
//	cout << "Length of list is = " << list.getLength() << endl;
	if (list.deleteAtHead())
	{
		cout << "Value deleted at head successfully" << endl;
	}
	else
	{
		cout << "Value not deleted at head" << endl;
	}
	list.printList();
/*	if (list.deleteAtTail())
	{
		cout << "Value deleted at tail successfully" << endl;
	}
	else
	{
		cout << "Value not deleted at tail" << endl;
	}
	list.printList();
	cout << "Value at head is : " << list.getHead() << endl;
	cout << "Value at tail is : " << list.getTail() << endl;
	cout << "all nodes deleted" << endl;
	list.deleteNodes();
	list.printList();   */
}


