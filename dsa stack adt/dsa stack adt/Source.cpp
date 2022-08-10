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
    MyStack(int s = 10)
    {
        size = s;
        top = -1;
        stack = new T[size];
    }
    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void resize(int s)
    {
     //   stack = new T[s];
        size = s;
        
    }
    void push(int value)
    {
       
        if (isFull())
        {
            resize(size * 2);
        }
       
        stack[++top] = value;
   
    }
    int pop()
    {
        if (!isEmpty())
            return stack[top--];
        else
            cout << "ERROR! Stack is empty" << endl;

    }
    int peak()
    {
        return stack[top];
    }
    int count()
    {
        return top + 1;
    }
    void printStack()
    {
        int squarebracketCheck = 0;
        int curleybracketCheck = 0;
        int roundbracketCheck = 0;
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i];
        }
        for (int i = 0; i < top; i++)
        {
            for (int j = 0; j <= top; j++)
            {
                if (stack[i] == '[' && stack[j] == ']' && i < j)
                {
                    
                    squarebracketCheck++;
                }
                if (stack[i] == '{' && stack[j] == '}' && i < j)
                {

                    curleybracketCheck++;
                }
                if (stack[i] == '(' && stack[j] == ')' && i < j)
                {

                    roundbracketCheck++;
                }
               
                
            }
            
        }
        if (squarebracketCheck > 0&& roundbracketCheck>0&& curleybracketCheck>0)
        {
            cout << "Your input is valid " << endl;
        }
        else
        {
            cout << "Your input is invalid" << endl;
        }
    }
    void pushString(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            push(str[i]);
        }
    }
};

int main()
{
    string value;
    cout << "Enter string :";
    cin >> value;
    cout << "Hello World!\n";
    MyStack<char> stack(3);
    
    stack.pushString(value);
     
       
    
    stack.printStack();
  //  stack.pop();
 //   cout << stack.peak() << endl;
  //  cout << stack.count()<< endl << endl;

  
}