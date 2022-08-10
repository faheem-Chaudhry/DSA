#include<iostream>
#include<fstream>
using namespace std;

int RatInAMaze(int** maze, int** solution, int Mx, int My, int n)
{
	//boundary check
	if (Mx == n - 1 && My == n - 1)
	{
		//at destination point place 1
		solution[Mx][My] = -1;
		return -1;
	}
	//valid moves within grid

	if ((Mx >= 0 && Mx < n) && (My >= 0 && My < n))
	{
		//when 0 found
		if (maze[Mx][My] == 0)
		{
			//place -1
			solution[Mx][My] = -1;
			//vertically check for movement to be inside grid only 
			if ((My >= 0 && My < n))
			{
				//move vertically
				if (RatInAMaze(maze, solution, Mx, My + 1, n) == -1)
				{
					return -1;
				}
			}
			//Horizontal check for movement to be inside grid only 
			if ((Mx >= 0 && Mx < n))
			{
				//move horizontally
				if (RatInAMaze(maze, solution, Mx + 1, My, n) == -1)
				{
					return -1;
				}
			}
			//backtracking
			solution[Mx][My] = 0;
		}
		return 0;
	}
}
int main()
{
	//n->size of grid
	int n = 0;
	int Mx = 0;   // Mx->initial x cord of mouse, My->inital y cord of mouse
	int My = 0;
	int Dx = 0;    //Dx->destination x cord,Dy->Destination y cord
	int Dy = 0; 
	fstream f;
	f.open("input.txt", ios::in);

	//taking inputs from file
	f >> n >> Mx >> My >> Dx >> Dy;
	//creating a integer type dynamic array to create and insert values of grid and a characater dynamic array
	int** arr = new int* [n];
	char** arr2 = new char* [n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		arr2[i] = new char[n];
	}
	//initializing dynamic integer array with 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	//intialzing character with null character
	char c = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//taking input from file
			f >> c;
			//set char array with file input
			arr2[i][j] = c;
			//if input taken from file is character 0 then place 0 integer array
			if (c == '0')
			{
				arr[i][j] = 0;
			}
			//if input taken from file is character 0 then place 0 integer array
			if (c == '1')
			{
				arr[i][j] = -1;
			}
		}
	}
	//close file
	f.close();

	//creating a dynamic solution array
	int** solution = new int* [n];
	for (int i = 0; i < n; i++)
	{
		solution[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			//setting all entries to 0
			solution[i][j] = 0;
		}
	}
	//sending integer array,solution array,initial cordinates of x,y  and size of grid in Rat In A Maze Function
	RatInAMaze(arr, solution, Mx, My, n);

	//opening file in output mode
	f.open("output.txt", ios::out);
	//output size of grid,initial x y cords of mouse, destination cords x and y in file
	f << n << endl << Mx << " " << My << endl << Dx << " " << Dy << endl;
	//output size of grid,initial x y cords of mouse, destination cords x and y in console
	cout << n << endl << Mx << " " << My << endl << Dx << " " << Dy << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			//via solution array
			if (solution[i][j])
			{
				//display path
				cout << "(" << i << "," << j << ") ";
				f << "(" << i << "," << j << ") ";
				//highlight correct path with sterics
				arr2[i][j] = '*';
			}
		}
	}
	cout << endl; f << endl;
	//For Displaying Grid
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			//Display Grid on Console
			cout << arr2[i][j] << " ";
			//Display Grid on File
			f << arr2[i][j] << " ";
		}
		cout << endl; f << endl;
	}
	//close file
	f.close();
	return 0;
}


















