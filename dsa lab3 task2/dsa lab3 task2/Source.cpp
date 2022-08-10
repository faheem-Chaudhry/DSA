#include"MyStack.h"
#include"MyStack.cpp"


int main()
{
    int a;
    MyStack<char> stack(12);
  
    char ch;
    do
    {
        cout << "Enter value :";
        cin >> a;
        stack.push(a);
        cout << "Do you want to enter more values then press y :";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
 
    int z, y;
    MyStack<char> stack2(12);

    for (int i = 0; i < stack.peak(); i++)
    {
        z = stack.peak();
        stack2.push(stack.pop());
        if (stack.peak() > z)
        {
            stack2.pop();
            stack2.push(stack.pop());
            if (stack.peak() > z)
            {
                y = stack.pop();
                stack.push(z);
                stack.push(y);
            }
            else
            {
                stack.push(z);
            }
        }
       
   }
    while (!stack2.isEmpty())
    {
        cout << stack2.pop() << endl;
    }
}