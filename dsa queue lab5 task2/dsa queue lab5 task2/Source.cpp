#include<iostream>
#include"MyQueue.h"
#include"MyQueue.cpp"
using namespace std;
int main()
{
	MyStack<int> stack;

	stack.push(1);
	stack.push(2);

	stack.push(3);

	stack.pop();
	stack.pop();


}