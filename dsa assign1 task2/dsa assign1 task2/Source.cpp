#include"StackADT.h"
#include"StackADT.cpp"
#include<iostream>
using namespace std;



int checkPunctuation(char s)
{            //this global  function check whether a character is punctuation and space or not.

        if (s == ' ' || s == '?' || s == '"' || s == ',' || s == '-' || s == '!' || s == 39 || s == ';' || s == ':' || s == '.')
        {
            return 1;
        }
        else
        {
            return 0;
        }
}
void Palindrome(string s)          //Global function that check validity
{

    MyStack<char> stack(100);     //initilize stack with 100 space
    MyStack<char> stack2(100);     //initilize stack2 with 100 space

    for (int i = 0; i < s.size(); i++)
    {                   // only push string characterwise in first stack other than punctuation

        if (checkPunctuation(s[i]) == 0)        //condition check
        {
            stack.push(s[i]);
        }
    }
    for (int i = s.size()-1; i >= 0; i--)
    {                // only push string characterwise in reverse order in 2nd stack other than punctuation

        if (checkPunctuation(s[i]) == 0)         //condition check
        {
            stack2.push(s[i]);
        }         
    }
    while (!stack.isEmpty())
    {
        if (stack.peak() == stack2.peak() || stack.peak() == stack2.peak()+32 || stack.peak()+32 == stack2.peak())
        {                   // check the condition a=A
            stack.pop();
            stack2.pop();
        }
        else
        {
            cout << "Your given string is not palindrome ";
            break;
        }
    }

    if (stack.isEmpty() && stack2.isEmpty())
    {
        cout << " Your given string is palindrome ";
    }
  
}
int main()
{
    string value;
    cout << "Enter string :";
    getline (cin,value);

    Palindrome(value);
    return 0;
}    