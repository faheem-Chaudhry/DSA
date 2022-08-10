#include "LinkList.h"
template<class T>
void LinkedList<T>::keyPresent(T value)
{
	int counter = 0;
	Node<T>* temp = head;
	while (temp!=NULL)
	{
		if (temp->data > value)
		{
			counter++;
		}
		temp=temp->next;
	}
	cout << "Values greater than " << value << " are : " << counter << endl;
}

template<class T>
void LinkedList<T>::keyPresentPart2(T value)
{
	int counter = 0;
	Node<T>* temp = head;
	while (temp != NULL)
	{
		if (temp->data == value)
		{
			counter++;
		}
		temp = temp->next;
	}
	cout << "Values equals to " << value << " are : " << counter << endl;
}
template<class T>
void LinkedList<T>::reverse()
{
	Node<T>* temp = head;
	Node<T>* prev = NULL;
	Node<T>* next = NULL;

	while (temp) 
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = prev;     // now head becomes tail



}
template<class T>
LinkedList<T>::LinkedList(const LinkedList& obj)
{                                            //copy constructor
	head->data = obj.head->data;
	head->next = obj.head->next;
	tail->data = obj.tail->data;
	tail->next = obj.tail->next;
}
template<class T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}
template<class T>
void LinkedList<T>::insertAtTail(T value)
{
/*	Node<T>* temp = head;
	while (temp->next!=NULL)
	{
    	temp = temp->next;
	}
	Node<T>* temp2 = new Node<T>(value);
		temp->next = temp2;
		temp2->next = NULL;    */



	Node<T>* temp = new Node<T>(value);

	if (isEmpty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
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
	}
}
template<class T>
void LinkedList<T>::printList()
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
bool LinkedList<T>::insertAfter(T val, T key)
{
	Node<T>* found = search(key);
	if (found)
	{
		Node<T>* newNode = new Node<T>(val);
		newNode->next = found->next;
		found->next = newNode;
		return true;
		if (found == tail)
		{
			tail = newNode;
			return true;
		}
	}
	else
		return false;
	//	cout << "Key Not found!" << endl;
}
template<class T>
bool LinkedList<T>::insertBefore(T val, T key)
{
	Node<T>* found = search(key);
	Node<T>* temp = head;
	if (found)
	{
		while (temp)
		{
			if (temp->next == found)
			{
				Node<T>* newNode = new Node<T>(val);
				temp->next = newNode;
				newNode->next = found;
				return true;
				break;
			}
			else
				temp = temp->next;
		}
	}
	else
		return false;
}
template<class T>
Node<T>* LinkedList<T>::search(T key)
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
bool LinkedList<T>::deleteAtHead()
{
	if (!isEmpty())
	{                 
		Node<T>* temp = head;
		head = head->next;
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
				temp2->next = NULL;
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
bool LinkedList<T>::deleteAfter(T key)
{
	Node<T>* found = search(key);
	Node<T>* temp = head;
	if (found)
	{
		while (temp)
		{
			if (found->next == temp)
			{
				found->next = temp->next;
				delete temp;
				return true;
				break;
			}
			else
				temp = temp->next;
		}
	}
	else
		return false;
}
template<class T>
bool LinkedList<T>::deleteBefore(T key)
{
	Node<T>* found = search(key);
	Node<T>* temp = head;
	if (found)
	{
		while (temp)
		{
			if (temp->next == found)
			{
				if (temp == head)
				{
					head = head->next;
					delete temp;
					break;
				}
				Node<T>* temp2 = head;
				while (temp2)
				{
					if (temp2->next == temp)
					{
						temp2->next = found;
						delete temp;
						return true;
						break;
					}
					else
					{
						temp2 = temp2->next;
					}
				}
				break;
			}
			else
				temp = temp->next;
		}
	}
	else
		return false;
}
template<class T>
Node<T>* LinkedList<T>::getNode(int n)
{                                  
	int counter = 0;
	Node<T>* temp = head;
	while (counter!=n)
	{
		temp = temp->next;
		counter++;
	}
	if (n > getLength())
	{
		return tail;
	}
	else
	{
		return temp;
	}
}
template<class T>
Node<T>* LinkedList<T>::SEARCH(T n)
{
	Node<T>* found = search(n);
	Node<T>* temp = head;
	if (found)
	{
		while (temp)
		{
			if (temp->next == found)
			{
				return temp->next;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	
	else
		cout << "Key Not found!" << endl;
	    return NULL;       
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

