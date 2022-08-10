#include <iostream>
#include <string>
#include"LinkList.h"
#include"LinkList.cpp"
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
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter a value to insert at tail: ";
		cin >> inputVal;
		list.insertAtTail(inputVal);
	}
	list.printList();
	int n;
	cout << "Enter value : ";
	cin >> n;
	list.keyPresent(n);
	cout << "Enter value : ";
	cin >> n;
	list.keyPresentPart2(n);
//	list.reverse();
	list.printList();
	return 0;

}







/*int main()
{
	LinkedList<int> list;
	int inputVal;
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
	cout << "Length of list is = " << list.getLength() << endl;
	int key;
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
	cout << "Enter the value you want to find in the list : ";
	cin >> key;
	cout << "Enter the value you want to insert before found value : ";
	cin >> inputVal;
	if (list.insertBefore(inputVal, key))
	{
		cout << "Value enter successfully before " << endl;
	}
	else
	{
		cout << "Input not found" << endl;
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
	cout << "Enter the value you want to delete before : ";
	cin >> key;
	if (list.deleteBefore(key))
	{
		cout << "Value delete before key successfully" << endl;
	}
	else
	{
		cout << " key not found for value deleyed before key" << endl;
	}
	list.printList();
	cout << "Enter the value you want to delete after : ";
	cin >> key;
	if (list.deleteAfter(key))
	{
		cout << "Value delete after key successfully" << endl;
	}
	else
	{
		cout << " key not found for value deleted after key" << endl;
	}
	list.printList();
	cout << "\nNode at 4th position: ";
	cout<<list.getNode(4);     

	return 0;
}    */