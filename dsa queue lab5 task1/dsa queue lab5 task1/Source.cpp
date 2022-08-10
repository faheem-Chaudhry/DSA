#include<iostream>
#include"MyQueue.h"
#include"MyQueue.cpp"
using namespace std;
MyQueue<char> reverse(MyQueue<char> q)
{
	// Size of queue
	int s = q.max();

	// Second queue
	MyQueue<char> ans;

	for (int i = 0; i < s; i++)
	{

		for (int j = 0; j < q.max() - 1; j++) {
			int x = q.Front();
			q.dequeue();
			q.enqueue(x);
		}

		ans.enqueue(q.Front());
		q.dequeue();
	}
	return ans;
}
int main()
{
	MyQueue<char> queue;
	queue.enqueue('D');
	queue.enqueue('S');
	queue.enqueue('A');
	queue.enqueue(' ');
	queue.enqueue('L');
	queue.enqueue('A');
	queue.enqueue('B');
	queue.print();

	MyQueue<char> reverse_queue = reverse(queue);

	reverse_queue.print();




/*	                    //*********************************************TASK2*******************
	cout << endl << endl << endl << "*********TASK2**************" << endl << endl;
	MyQueue<string>* queue2;
	PriorityQueue<string> priority;
	queue2 = &priority;

	queue2->enqueue("Clerk:3");
	queue2->enqueue("Supervisor:2");
	queue2->enqueue("Principal:0");
	queue2->enqueue("Manager:1");


//	queue2->print();
	cout << endl << endl;
	queue2->dequeue();
	queue2->dequeue();
	queue2->dequeue();
	queue2->dequeue();
	cout << endl;
	queue2->print();     */
}              