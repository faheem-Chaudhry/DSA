#include<iostream>
using namespace std;
void printND(int dimensions)
{
	char ch = 'D';
	char ch2 = 'i';
	int counter1 = 1;
	int counter2 = 2;
	for (int i = 1; i <= dimensions; i++)
	{
	
		cout << ch2 << counter1;
		for (int j = i+1; j <= dimensions; j++)
		{
			cout << ch << counter2;
			counter2++;
		}
		counter2 = i + 2;
		if(i!=dimensions)
			cout << " + ";
		counter1++;
	}
}
int main()
{
	int dimensions;
	cout << endl;
	cout << "Enter dimensions for input :";
	cin >> dimensions;
	cout << endl;
	printND(dimensions);
}