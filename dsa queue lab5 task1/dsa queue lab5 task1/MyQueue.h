#pragma once
#include <iostream>
#include<string>
using namespace std;
template<class T>
class MyQueue
{
protected:
	T* queue;
    int front;
    int rear;
    int count;
    int size;
public:
    MyQueue()
    {
        size = 25;
        front = 0;
        count = 0;
        rear = 0;
        queue = new T[size];
    }
    virtual void enqueue(T value);

    MyQueue(const MyQueue& q1)
    {
        size = q1.size;
        rear = q1.rear;
        front = q1.front;
        count = q1.count;
        queue = q1.queue;
    }

    bool isEmpty();
    bool isFull();
    void dequeue();
    void print();   
    T Front();  
    int Rear();
    int max();
    void resize(int newsize);
};

template<class T>
class PriorityQueue : public MyQueue<T>
{
public:
  
    void enqueue(T value);
   
};    

