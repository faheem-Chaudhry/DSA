#include <iostream>
using namespace std;
template <class T>
class Set
{
private:
	T* arr1;
	int s;
	int CurrPosition;

public:
	Set()
	{
		s = 0;
		CurrPosition = 0;
		arr1 = new T[s];
		for (int i = 0; i < s; i++)
		{
			arr1[i] = 0;
		}
	}
	Set(T array[], int S)
	{
		s = S;
		arr1 = new T[s];
		for (int i = 0; i < s; i++)
		{
			arr1[i] = array[i];
		}
	}
	
	void create()
	{
		cout << "WE ARE IN CREATE FUNC" << endl;
		cout << "set size" << endl;
		cin >> s;
		cout << "create an array" << endl;
		arr1 = new T[s];
		for (int i = 0; i < s; i++)
		{
			cin >> *(arr1 + i);
		}
		cout << "The array is :" << endl;
		for (int i = 0; i < s; i++)
		{
			cout << *(arr1 + i);
		}
	}
	void insert(T element)
	{
		cout << "WE ARE IN INSERT FUNC" << endl;

		s = s++;						//increasing size of array
		arr1[s - 1] = element;			//putting that element in array on size-1 cell
		cout << endl;
		cout << "now new array is:" << endl;
		for (int i = 0; i < s; i++)
		{
			cout << arr1[i];
		}

	}
	void ismember(T val)
	{

		for (int i = 0; i < s; i++)						//we are comparing number with the array
		{												//hence we will tell that this element is present or not	
			if (arr1[i] == val)
			{
				cout << "yes this is present in array" << endl;
				break;
			}
		}
		for (int i = 0; i < s; i++)
		{
			if (arr1[i] != val)
			{
				cout << "No this is Not present in array" << endl;
				break;
			}

		}
	}
	void remove()			//this function will delete an element in an array
	{
		int rem = 0;
		int j;
		cout << "\nEnter element you want to remove: ";
		cin >> rem;
		for (int i = 0; i < size; i++)
		{
			if (arr1[i] == rem)
			{
				for (j = i; j < (size - 1); j++)
					arr1[j] = arr1[j + 1];
				i--;
				size--;
			}
		}
	}
	void Union(Set ob2)
	{
		int flag;
		int j;
		for (int i = 0; i < size; i++)
		{
			cout << arr1[i] << " ";
		}
		for (j = 0; j < ob2.size; j++)
		{
			flag = 0;
			for (int i = 0; i < size; i++)
			{
				if (arr1[i] == ob2.arr1[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag != 1)
			{
				cout << ob2.arr1[j] << " ";
			}
		}
	}
};



int main()
{
	Set<int> a;								//we are using integer data type this time
	a.create();
	cout << endl;
	int element;
	cout << endl;
	cout << "which element u want to insert?" << endl;
	cin >> element;
	a.insert(element);
	cout << endl;
	cout << "which element u want to know that this is present in this array or not?" << endl;
	int pa;
	cin >> pa;
	a.ismember(pa);
	a.remove();
	cout << "Creating another array: " << endl;
	Set<int> obj2;
	obj2.create();
	cout << "\n*UNION OF TWO SETS*\n";
	a.Union(obj2);
}