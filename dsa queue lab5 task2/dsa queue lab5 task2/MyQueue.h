#pragma once
#include <iostream>
#include<vector>
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
    class MyStack
    {
    public:
        MyQueue<int> queue1;
        MyQueue<int> queue2;
        vector<int> V1;
        int count = 0;
        int count2 = 0;

        void push(T value)
        {
          
            queue1.enqueue(value);
            V1.push_back(queue1.dequeue());
         //   V1.insert(V1.end() – count, value);
        //    count++;


        }
        void pop()
        {
            queue2.enqueue(V1.end() – count);
            count2++;
        }






    };

