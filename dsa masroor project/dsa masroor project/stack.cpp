#include "stack.h"

//#include"Stack.h"
template<class T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}
template<class T>
T LinkedList<T>::getHead()
{
	return head->data;
}
template<class T>
T LinkedList<T>::getTail()
{
	return tail->data;
}

template<class T>
void LinkedList<T>::insertAtTail(T value)
{
	Node<T>* temp = new Node<T>(value);

	if (isEmpty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		tail->next = head;
	}
}
template<class T>
void LinkedList<T>::insertAtHead(T value)
{
	Node<T>* newNode = new Node<T>(value);

	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
		tail->next = head;
	}
}
template<class T>
void LinkedList<T>::printList()
{
	Node<T>* temp = head;
	while (temp!=tail)
	{
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << temp->data << " --> ";
	temp = temp->next;
	cout << "NULL" << endl;
}
template<class T>
bool LinkedList<T>::deleteAtHead()
{
	if (!isEmpty())
	{
		Node<T>* temp = head;
		head = head->next;
		tail->next = head;
		delete temp;
		return true;
		if (isEmpty())
			tail = NULL;
	}
	return false;
}
template<class T>
bool LinkedList<T>::deleteAtTail()
{
	if (!isEmpty())
	{

		Node<T>* temp = head;
		while (temp)
		{
			if (temp->next == tail)
			{
				Node<T>* temp2 = temp;
				temp = tail;
				tail = temp2;
				temp2->next = head;
				delete temp;
				return true;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}

		if (isEmpty())
			tail = NULL;
	}
	return false;
}
template<class T>
int LinkedList<T>::getLength()
{
	Node<T>* temp = head;
	int counter = 0;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	return counter;

}
                         //Task 4
template<class T>
void LinkedList<T>::deleteNodes()
{
	Node<T>* temp = head;
	while (temp)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}
