#pragma once
                      //    BSEF19M011                     FAHEEM KHALID
#include<iostream>
using namespace std;
template<class Element>
class Set
{
private:
	int size;
	Element* array;
public:
	Set()                         //constructor
	{
		size = 0;
		array = new Element[size];
	}
	~Set()
	{
		delete array;
	}
	void Insert(Element value);
	void remove(int a);
	void Ismember(int a);
	void intersection(Set *s);
	void Issubset(Set *s);
	void Union(Set *s);
	void print();
};


template<class Element>
void Set<Element>::Insert(Element value)                //Insert Function Called
{
	array[size] = value;
	size++;
}
template<class Element>
void Set<Element>::remove(int a)                      //Remove Function Called
{
	cout << endl << "remove function call :" << endl;
	for (int j = 0; j < size; j++)
	{
		if (array[j] == a)
		{
			array[j] = array[j + 1];
			size = size - 1;
		}
	}
}
template<class Element>
void Set<Element>::Ismember(int a)                    //Ismember Function Called
{
	cout << endl << "find member function call :" << endl;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == a)
			cout << "'" << a << "' is the member of set" << endl;
		else if (array[i] != a && array[i] == size - 1)
		{
			cout << "'" << a << "' is not the member of set" << endl;

		}
	}
}
template<class Element>
void Set<Element>::intersection(Set *s)                   //Intersection Function Called
{
	cout << endl << "After performing Intersection on sets :" << endl;
	cout << " { ";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= s->size; j++)
		{
			if (array[i] == s->array[j])
			{
				cout << array[i] << ",";
			}
		}
	}
	cout << " } ";
}
template<class Element>
void Set<Element>::Issubset(Set *s)                 //Issubset Function Called
{
	cout << endl << "After performing Subset on sets :" << endl;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s->size; j++)
		{
			if (array[i] == s->array[j])
			{
				count++;
			}
		}
	}
	if (count == size)
	{
		cout << "1st set is subset of 2nd set" << endl;
	}
	else
	{
		cout << " 1st set is not subset of 2nd set" << endl;
	}
}
template<class Element>
void Set<Element>::Union(Set *s)                       //Union Function Called
{
	cout << endl << "After performing Union on sets :" << endl;
	cout << " { ";
	int val;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s->size; j++)
		{
			if (array[i] == s->array[j])
			{
				val = j;

			}
		}
	}
	for (int j = val + 1; j <= s->size; j++)
	{
		array[size] = s->array[j];
		if (j != s->size)
		{
			size++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ",";
	}
	cout << " } ";
}

template<class Element>
void Set<Element>::print()                            //Print Function Called
{
	cout << endl;
	cout << "{";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ",";
	}
	cout << "}";
	cout << endl;
}

