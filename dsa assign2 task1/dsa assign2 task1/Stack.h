#pragma once
#include <iostream>
#include<string>
using namespace std;
template<class T>
class MyStack
{
    T* stack;
    int size;
    int top;
public:
    MyStack(int s)
    {
        size = s;
        top = -1;
        stack = new T[size];
    }

    bool isFull();
    bool isEmpty();
    void resize(T);
    void push(T);
    T pop();
    T peak();
    void printStack();
    void pushString(string);
    int count();
};


