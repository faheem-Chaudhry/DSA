#include <iostream>
#include<string>
#include<cmath>
using namespace std;

class StudentMaxHeap;

class student
{

private:
	string name;
	double cgpa;
	int rollNum;
public:
	friend class StudentMaxHeap;
	student()
	{
		name = "";
		cgpa = 0.0;
		rollNum = 0;
	}
	student(int rollnum, string Name, double CGPA)
	{
		name = Name;
		cgpa = CGPA;
		rollNum = rollnum;
	}

};

class StudentMaxHeap
{
	int point;
	int currSize;
	int maxSize;
	student* arr;
public:
	StudentMaxHeap(int s);
	~StudentMaxHeap();
	bool insert(int rollnum, string Name, double CGPA);
	bool extractTooper();
	bool balanceAfterInsertion(int val);
	StudentMaxHeap& operator = (StudentMaxHeap&);
	bool balanceAfterExtraction(int val);
	bool isEmpty();
	bool isFull();
	void show();
	void showTree();
};
StudentMaxHeap::StudentMaxHeap(int s)
{
	this->currSize = 0;
	maxSize = pow(2, s) - 1;
	arr = new student[maxSize];
	point = 1;
}

StudentMaxHeap::~StudentMaxHeap()
{
	delete arr;
}
bool StudentMaxHeap::insert(int rollnum, string Name, double CGPA)
{

	if (currSize - 1 == point)
	{
		return false;
	}
	else
	{
		student temp(rollnum, Name, CGPA);
		arr[point] = temp;
		balanceAfterInsertion(point);
		point++;
		return true;
	}
}


bool StudentMaxHeap::extractTooper()
{
	if (point == 1)
	{
		student temp(0, "", 0);
		arr[point--] = temp;
		return true;
	}
	else if (point == 0)
	{
		return false;
	}
	else
	{
		cout << endl;
		cout << "Student Name: " << arr[1].name << endl;
		cout << "Student Roll No: " << arr[1].rollNum << endl;
		cout << "Student CGPA: " << arr[1].cgpa << "\n";
		arr[1] = arr[point - 1];
		balanceAfterExtraction(point);
		student temp(0, "", 0);
		arr[point--] = temp;
		return true;
	}

}

bool StudentMaxHeap::balanceAfterInsertion(int val)
{
	if (val == 1)
	{
		return false;
	}
	else
	{
		int max;
		int temp = val;
		if (val % 2)
		{
			if (arr[val].cgpa < arr[val - 1].cgpa)
			{
				max = val - 1;
			}
			else
			{
				max = val;
			}
			temp = val / 2;
			if (arr[temp].cgpa < arr[max].cgpa)
			{
				student t = arr[temp];
				arr[temp] = arr[max];
				arr[max] = t;
			}
		}
		else
		{
			temp = temp / 2;
			max = val;
			if (arr[temp].cgpa < arr[max].cgpa)
			{
				student t = arr[temp];
				arr[temp] = arr[max];
				arr[max] = t;
			}
		}
		balanceAfterInsertion(temp);
	}
	return true;
}
StudentMaxHeap& StudentMaxHeap::operator = (StudentMaxHeap& copy)
{
	StudentMaxHeap obj(log2(maxSize + 1));

	for (int i = 0; i < currSize; i++)
	{
		obj.arr[i] = copy.arr[i];
	}

	obj.currSize = copy.currSize;
	obj.maxSize = copy.maxSize;

	return obj;
}
bool StudentMaxHeap::balanceAfterExtraction(int val)
{
	if (val == 1)
	{
		return false;
	}
	else
	{
		int max;
		int temp = val;
		if (val % 2)
		{
			if (arr[val].cgpa < arr[val - 1].cgpa)
			{
				max = val - 1;
			}
			else
			{
				max = val;
			}
			temp = val / 2;
			if (arr[temp].cgpa < arr[max].cgpa)
			{
				student t = arr[temp];
				arr[temp] = arr[max];
				arr[max] = t;
				balanceAfterExtraction(point);
			}
		}
		else
		{
			temp = temp / 2;
			max = val;
			if (arr[temp].cgpa < arr[max].cgpa)
			{
				student t = arr[temp];
				arr[temp] = arr[max];
				arr[max] = t;
				balanceAfterExtraction(point);
			}
		}
		balanceAfterExtraction(temp);
	}
	return true;
}
bool StudentMaxHeap::isEmpty()
{
	if (currSize == 0)
	{
		return true;
	}
	return false;
}

bool StudentMaxHeap::isFull()
{
	if (currSize == maxSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void StudentMaxHeap::show()
{
	cout << endl;
	for (int i = 1; i < point; i++)
	{
		cout << endl;
		cout << "Student Name: " << arr[i].name << endl;
		cout << "Student Roll No: " << arr[i].rollNum << endl;
		cout << "Student CGPA: " << arr[i].cgpa << "\n";
	}
}

void StudentMaxHeap::showTree()
{
	int flag = 0, check = 1;
	for (int i = 1; i < point; i++)
	{
		cout << arr[i].cgpa << " ";
		flag++;
		if (flag == check)
		{
			flag = 0;
			cout << endl;
			check *= 2;
		}
	}
	cout << endl;
}

int main()
{
	cout << "********************************************************MENU************************************************************" << endl;
	StudentMaxHeap h(20);
	int rollNo = 0;
	string name = "";
	double cgpa = 0;


	cout << endl;
	cout << "1-Insert a new student" << endl;
	cout << "2-Remove student with max cgpa and display" << endl;
	cout << "3-display the list of students in descending order" << endl;
	cout << "4-display the list of students in level order traversal" << endl;
	cout << "5-exit" << endl;

	cout << endl;
	int choice = 0;
	cout << "Enter your option from MENU: ";
	cin >> choice;
	do
	{
		if (choice == 1)
		{
			cout << "How Many Students Record you want to enter: ";
			int record = 0;
			cin >> record;
			for (int i = 0; i < record; i++)
			{
				cout << endl;
				cout << "\t\t\t\tEnter data of Student " << i + 1;
				cout << endl << endl;
				cout << "Enter Name of student " << i + 1 << ": ";
				cin.ignore();
				getline(cin, name);


				cout << "Enter Roll No of student " << i + 1 << ": ";
				cin >> rollNo;;
				cout << "Enter GPA of student " << i + 1 << ": ";
				cin >> cgpa;

				h.insert(rollNo, name, cgpa);
			}

		}
		if (choice == 2)
		{
			cout << endl << "Extracting Topper" << endl;
			h.extractTooper();

		}
		if (choice == 3)
		{
			cout << endl << "Student Record in descending order is given by:" << endl;
			h.show();
			cout << endl;

		}
		if (choice == 4)
		{
			cout << "Level Order Tree" << endl;
			h.showTree();
		}

		cout << endl;
		cout << "********************************************************MENU************************************************************" << endl;

		cout << endl;
		cout << "1-Insert a new student" << endl;
		cout << "2-Remove student with max cgpa and display" << endl;
		cout << "3-Display the list of students in descending order" << endl;
		cout << "4-Display the list of students in level order traversal" << endl;
		cout << "5-Exit" << endl;
		cout << "Enter Your Choice Again: ";
		cin >> choice;
	} while (choice != 5);

}





