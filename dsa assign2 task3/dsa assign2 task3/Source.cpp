#include <iostream>
using namespace std;
#include"xorLinklist.h"
int main()
{
	
	LinkedList list;
	int insertAtHead = 0;

	//insert At Head

	cout << "Insert At Head: " << endl;
	cout << "How Many Values You Want To insert at Head: ";
	int count1 = 0;
	cin >> count1;
	for (int i = 0; i < count1; i++)
	{
		cout << "Enter Value at Head of Node " << i + 1 << ": ";
		cin >> insertAtHead;
		list.insertAtHead(insertAtHead);
	}
	cout << endl;
	cout << "Your Link List Is : ";
	list.print();
	cout << endl;

	//insert At Tail

	int insertAtTail = 0;
	int count2 = 0;
	cout << "Insert At Tail: " << endl;
	cout << "How Many Values You Want To insert at Tail: ";
	cin >> count2;
	for (int i = 0; i < count2; i++)
	{
		cout << "Enter Value at Tail of Node " << i + 1 << ": ";
		cin >> insertAtTail;
		list.insertAtTail(insertAtTail);
	}
	cout << endl;
	cout << "Your Link List Is : ";
	list.print();

	//Remove At Head

	list.removeAtHead();
	cout << endl;
	cout << "After Removing Head: " << endl;
	cout << "Your Link List Is : ";
	list.print();

	//remove At Tail

	list.removeAtTail();
	cout << endl;
	cout << "After Removing Tail: " << endl;
	cout << "Your Link List Is : ";
	list.print();

	//search
	int key = 0;
	cout << endl;
	cout << "Enter an element to be searched in list: ";
	cin >> key;
	cout << endl;
	cout << "Searching element '" << key << "' in list" << endl;
	if (list.search(key))
	{
		cout << "Element found in list" << endl;
	}
	else
	{
		cout << "Element not found in list" << endl;
	}

	cout << endl;
	return 0;
}