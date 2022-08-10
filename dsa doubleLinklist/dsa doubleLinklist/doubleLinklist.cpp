#include "doubleLinklist.h"
template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList& obj)
{                                            //copy constructor
	head->data = obj.head->data;
	head->next = obj.head->next;
	tail->data = obj.tail->data;
	tail->next = obj.tail->next;
}
template<class T>
bool DLinkedList<T>::isEmpty()
{
	return head == NULL;
}
template<class T>
Node<T>* DLinkedList<T>::getHead()
{                                          //get head
	return head;
}
template<class T>
Node<T>* DLinkedList<T>::getTail()
{                                                  //get tail
	return tail;
}
template<class T>
void DLinkedList<T>::insertAtTail(T value)
{
	Node<T>* temp = new Node<T>(value);    //make new node with given value
	Node<T>* temp2 = tail;

	if (isEmpty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		tail->prev = temp2;
	}
}
template<class T>
void DLinkedList<T>::insertAtHead(T value)
{
	Node<T>* newNode = new Node<T>(value);            //make new node with given value

	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}
template<class T>
void DLinkedList<T>::printList()
{
	Node<T>* temp = head;
	while (temp)
	{
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}
template<class T>
bool DLinkedList<T>::deleteAtHead()
{
	if (!isEmpty())
	{
		Node<T>* temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
		return true;
		if (isEmpty())
			tail = NULL;
	}
	return false;
}
template<class T>
bool DLinkedList<T>::deleteAtTail()
{
	if (!isEmpty())
	{
		Node<T>* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
		return true;
		if (isEmpty())
			tail = NULL;
	}
	return false;


}
template<class T>
bool DLinkedList<T>::deleteAfter(T key)
{
	Node<T>* found = search(key);     //make new node with given value

	
    if (found)
	{
		if (found == tail)
		{                        //if newnode = tail
			cout << "The given key is tail";
			return false;
		}

		Node<T>* temp = found->next;
		Node<T>* temp2 = temp->next;
		if (temp2 == NULL)        //this condition check whether the node after found->next exist or not...
		{
			cout << "pak";
			tail = found;
			found->next = NULL;
			delete temp;
			return true;
		}
		else
		{
			found->next = temp2;
			temp2->prev = found;
			delete temp;
			return true;
		}


	}  
	else
		return false;
}
template<class T>
Node<T>* DLinkedList<T>::search(T key)
{
	Node<T>* temp = head;
	while (temp)
	{
		if (temp->data == key)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}
template<class T>
bool DLinkedList<T>::insertAfter(T val, T key)
{
	Node<T>* found = search(key);    //make new node with given value
	if (found)
	{
		if (found == tail)
		{
			Node<T>* newNode = new Node<T>(val);    //make new node with the value to be inserted
			newNode->next = NULL;
			newNode->prev = found;
			found->next = newNode;
			tail = newNode;
			return true;
		}
		Node<T>* newNode = new Node<T>(val);    //make new node with the value to be inserted
		newNode->next = found->next;
		newNode->prev = found;
		found->next = newNode;
		return true;

	}
	else
		return false;
}
template<class T>
void DLinkedList<T>::setHead(Node<T>* HEAD)
{
	Node<T>* found = search(HEAD->data);   //first we check the data member of given node exist in linlist or not
	if (found)
	{                                  //if it exist
		Node<T>* temp = found->prev;
		Node<T>* temp2 = found->next;
		temp->next = temp2;           
		temp2->prev = temp;            
	

		head->prev = found;       //now insert it at head
		found->next = head;
		found->prev = NULL;
		head = found;
	}
	if(!found)
	{                           //if it not exist
		head->prev = HEAD;
		HEAD->next = head;
		HEAD->prev = NULL;
		head = HEAD;
	} 
}
template<class T>
void DLinkedList<T>::setTail(Node<T>* TAIL)
{
	Node<T>* found = search(TAIL->data);   //first we check the data member of given node exist in linlist or not
	if (found)
	{                                  //if it exist
		Node<T>* temp = found->prev;
		Node<T>* temp2 = found->next;
		temp->next = temp2;
		temp2->prev = temp;
		

		tail->next = found;    //now insert it at tail
		found->prev = tail;
		found->next = NULL;
		tail = found;
	}
	if (!found)
	{                           //if it not exist
		tail->next = TAIL;
		TAIL->prev = tail;
		TAIL->next = NULL;
		tail = TAIL;
	}
}
template<class T>
Node<T>* DLinkedList<T>::getNode(int n)
{
	int counter = 0;
	Node<T>* temp = head;         //make new node and initilize it with head
	while (counter != n)
	{
		temp = temp->next;
		counter++;
	}
	if (n > getLength())
	{                     //this check whether the given value is greater than total count of linklist or not
		return tail;
	}
	else
	{
		return temp;
	}
}
template<class T>
int DLinkedList<T>::getLength()
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
