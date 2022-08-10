#include<iostream>
using namespace std;
int counter = 0;        //  for task 3
int counter2 = 0;       // for task 1

void countCharacters(char* str)        //task 1
{
	counter2++;
	if (*str == '\0')
	{
		cout << counter2-1;
		return ;
	}
    countCharacters(str + 1);
}


void max(int* arr, int comparisor, int size)     //task 2
{
	int size2;
	size2 = size;
	int* arr2;
	arr2 = new int[size2];
	arr2 = arr;
	int temp;
	temp = comparisor;
	if (size2 == 0)
	{
		cout << "greatest value in array is : " << comparisor;
		return;
	}

	if (arr2[size2] > temp)
	{
		temp = arr2[size2];
	}
	max(arr2, temp, size2-1);
}

bool search(int array[], int start_index, int end_index, int element, int size)   //task 3
{
	if (counter>size/2)
	{
		return false;
	}
	counter++;
	int middle;
	middle = (end_index + start_index) / 2;
	if (array[middle] == element)
	{
		return true;
	}

	if (array[middle] > element)
	{
		end_index = middle - 1;
	}

	if (array[middle] < element)
	{
		start_index = middle + 1;
	}
	search(array, start_index, end_index, element,size);
}

void replace(char* str, char from, char to)       //task 4
{
	if (*str == '\0')
		return;

	if (*str == from)
	{
		*str = to;
	}
	replace(str + 1, from, to);
}
int main()
{
//	********************************** TASK 1 ************************************
cout << "**************************** TASK 1 ***********************************" << endl;

	char string[10] = "Faheem";
	 countCharacters(string);

//	********************************** TASK 2 ************************************
	cout << "\n**************************** TASK 2 ***********************************" << endl;
	int size ;
	cout << "Enter size of array : ";
	cin >> size;
	int *array;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter val : ";
		cin >> array[i];
	}
	max(array, array[0], size-1);   

//	********************************** TASK 3 ************************************
	cout << "\n**************************** TASK 3 ***********************************" << endl;

	int Size;
	cout << "Enter size of array : ";
	cin >> Size;
	int* arr;
	arr = new int[Size];
	cout << "enter values in assending order in order for binary search" << endl;
	for (int i = 0; i < Size; i++)
	{
		cout << "Enter val : ";
		cin >> arr[i];
	}
	int n;
	cout << "Enter element you want to find : ";
	cin >> n;
	
	if (search(arr, 0, Size - 1, n, Size))
	{
		cout << "element found successfully";
	}
	else
	{
		cout << " element not found";
	}  


//	********************************** TASK 4 ************************************
	cout << "\n**************************** TASK 4 ***********************************" << endl;

	char str[50];
	cout << "Enter string : ";
	cin >> str;
	char c1;
	cout << "Enter character to find : ";
	cin >> c1;
	char c2;
	cout << "Enter character to replace : ";
	cin >> c2;
    replace( str, c1, c2);
	cout << str;   
	return 0;
}