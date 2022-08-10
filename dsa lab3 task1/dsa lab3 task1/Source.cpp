#include"MyStack.h"
#include"MyStack.cpp"
void Validity(string s)          //Global function that check validity
{
    char check1 = ' ';            //variable that store previous value of push

    MyStack<char> stack(12);     //initilize stack with 12 space

    for (int i = 0; i < s.size(); i++)
    {               
        stack.push(s[i]);  

        if ((check1 == '[' && stack.peak() == ']') || (check1 == '{' && stack.peak() == '}') || (check1 == '(' && stack.peak() == ')'))
     
         // check1 stores previous value and stack.peak shows current value in this way they are compared
        
        {
           stack.pop();
           stack.pop();
        }
              
         check1 = stack.peak();
    }
    if (stack.isEmpty())         // In the end if stack is empty then user enter valid input
    {
        cout << "You enter valid input" << endl;
    }
    else   //if something remains in stack then this messege will be shown
    {
        cout << "You enter invalid input";
    }
}
int main()
{
    string value;
    cout << "Enter string :";
    cin >> value;

    Validity(value);
    return 0;
}