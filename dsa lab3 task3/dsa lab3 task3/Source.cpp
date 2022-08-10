#include"MyStack.h"
#include"MyStack.cpp"
/*void formulaCheck(string str)
{
    string check = "";
    char check2;
    MyStack<string> stack(14);
    if (str[0] >= 65 && str[0] <= 90)
    {                                // condition check for valid atom
        for (int i = 0; i < str.size(); i++)
        {
            for (int j = 1; j < str.size(); j++)
            {

                if (( str[i] >= 65 && str[i] <= 90) && ( str[j] >= 97 && str[j] <= 122) && !((str[j + 1] >= 48) && (str[j + 1] <= 57)))
                {                         //Condition check for Single Atom without counting 

                    check += str[i];
                    check += str[j];
                    stack.push(check);
                    check = "";
                    
                }
                else  if (( str[i] >= 65 && str[i] <= 90) && ( str[j] >= 48 && str[j] <= 57))
                {                   //Condition check for Single Atom with counting 
                    check += str[i];
                    for (int k = 1; k <= str[j] - 48; k++)
                    {
                        stack.push(check);
                    }
                    check = "";

                }
                else if (( str[i] >= 65 && str[i] <= 90) && ( str[j] >= 97 && str[j] <= 122) && (str[j + 1] >= 48 && str[j + 1] <= 57))
                {                       //Condition check for Single Atom with two characters with counting 
                    check += str[i];
                    check += str[j];
                    for (int k = 1; k <= str[j + 1] - 48; k++)
                    {
                        stack.push(check);
                    }
                    check = "";
                }

               
            }
        }
    }
    else
    {
        cout << "Enter valid name of atom";
      
    }
    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }

    
}   */

int main()
{
    string value;
    cout << "Enter string :";
    cin >> value;
    
 //   formulaCheck(value);


}