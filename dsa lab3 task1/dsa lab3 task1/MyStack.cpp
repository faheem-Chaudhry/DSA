#include "MyStack.h"
template<class T>
bool MyStack<T>::isFull()
{                                //Function to tell stack is full
    return top == size - 1;
}
template<class T>
bool MyStack<T>::isEmpty()
{                               //function to tell stack is empty
    return top == -1;
}
template<class T>       
void MyStack<T>::resize(int newSize)
{                                        //resize function
    T* temp = new T[newSize];
    for (int i = 0; i < newSize; i++)
    {
        temp[i] = stack[i];
    }
    delete[] stack;
    stack = temp;
    temp = nullptr;
    size = newSize;

}
template<class T>
void MyStack<T>::push(int value)
{
                                    //Push function
    if (isFull())
    {
        resize(size * 2);
    }

    stack[++top] = value;

}
template<class T>
int MyStack<T>::pop()
{                                //POP function
    if (count() == size / 4)
    {
        resize(size / 2);
    }

    return stack[top--];

}
template<class T>
char MyStack<T>::peak()
{                               //    Peak/Top function
    return stack[top];
}
template<class T>
void MyStack<T>::printStack()
{                              //Print function
   
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i];
    }
}

template<class T>
void MyStack<T>::pushString(string str)  
          //This function push the whole string in the stack at once sometimes we need this function
{
    for (int i = 0; i < str.size(); i++)
    {
        push(str[i]);
    }
}
template<class T>
int MyStack<T>::count()         //Function to check count of stack
{
    return top + 1;
}
