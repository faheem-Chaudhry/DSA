#include"MyStack.h"
#include"MyStack.cpp"
#include<vector>
void isBalance(string s)          //Global function that check IsBalance
{
    char check1 = ' ';            //variable that store previous value of push

    MyStack<char> stack(12);     //initilize stack with 12 space

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '{' || s[i] == '}' || s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']')
        {
            stack.push(s[i]);
        }

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
        cout << "Your expression is valid and balanced" << endl;
    }
    else   //if something remains in stack then this messege will be shown
    {
        cout << "You enter invalid expression";
    }
}
int Operator(char check)
{
        // As + and -    or    / and *  are of same precedence so we made this function to minimize complexcity

    if (check == '+' || check == '-')
    {
        return 1;
    }
    else if (check == '/' || check == '*')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
void infixToPostfix(string s)
{
    vector<char>myVector;                     //      Final result store in this vector

    MyStack<char> stack2(12);     //initilize stack with 12 space
 
    for (int i = 0; i < s.size(); i++)
    {
        if (myVector.size()==0 && ((s[i] >= 97 && s[i] <= 122)||(s[i] >= 48 && s[i] <= 57)))
        {                                        
                                        // condition or 1st variable to put on vector
            myVector.push_back(s[i]);
        }
        if (s[i] == '(')
        {                            //condition for opening small bracket
            stack2.push(s[i]);
        }
        if (s[i] == ')')
        {                                       //condition for closing small bracket
            while ( stack2.peak() != '('  )
            {
                myVector.push_back(stack2.peak());
                stack2.pop();
            }
            stack2.pop();           // pop bracket from stack
        }
        
        if ((Operator(s[i]) == 1 || Operator(s[i]) == 2 || s[i] == '(') && ((s[i+1] >= 97 && s[i+1] <= 122)||(s[i+1]>=48 && s[i+1]<=57)))
        {                                 
                                              // condition to put variables in vector
            myVector.push_back(s[i+1]);
        }
  
        if ((Operator(s[i]) == 1 || Operator(s[i]) == 2) && (stack2.isEmpty() || stack2.peak()=='('))
        {                      
                                 //condition to put only 1st operator on stack
            stack2.push(s[i]);
        }

        if (((stack2.peak() == '/'|| stack2.peak()=='*') && Operator(s[i + 1]) == 1) || ((stack2.peak() == '+' || stack2.peak() == '-') && Operator(s[i + 1]) == 1) || ((stack2.peak() == '/' || stack2.peak() == '*') && Operator(s[i + 1]) == 2))
        {
                         //condition to put operators on stack and then push on vector after ther are checked

            myVector.push_back(stack2.peak());
            stack2.pop();
            if ((stack2.peak() == '+' || stack2.peak() == '-') && Operator(s[i + 1]) == 1)
            {
                myVector.push_back(stack2.peak());
                stack2.pop();
            }
            stack2.push(s[i + 1]);
       
        }
       if ((stack2.peak() == '+' || stack2.peak() == '-') && Operator(s[i + 1]) == 2)
        {                      
                                    //check if + or - is on stack then we can put * and / on stack

            stack2.push(s[i + 1]);
        }     
    }
    while (!stack2.isEmpty())
    {                              //    pop operators from stack and push them on vector
        myVector.push_back(stack2.peak());
        stack2.pop();
    }
    cout << "ANS = ";
    for (int i = 0; i < myVector.size(); i++)
    {
                      //   Show result

        cout << myVector[i] << " ";
    }
    cout << endl;

}

void Evaluate(string s,int Case)
{
     MyStack<int> stack3(12);     //initilize stack with 12 space
  
     if (Case == 1)
     {
         int k;            
         int val = 0;  
         int increment = 0;
         int answer = 0;
         int check = 0; int check2 = 0;           
         for (int i = 0; i < s.size(); i++)
         {  
             k = i;
             if (s[i] == '+')
             {                     // Condition for sum

                 check = stack3.pop() + stack3.pop();
                 stack3.push(check);
                 check = 0;
             }

             if (s[i] == '-')
             {                               //  condition for subtraction
                 check = stack3.pop();
                 check2 = stack3.pop();
                 stack3.push(check2 - check);
                 check = 0;
                 check2 = 0;
             }
             if (s[i] == '/')
             {                              // Condition for division
                 check = stack3.pop();
                 check2 = stack3.pop();
                 stack3.push(check2 / check);
                 check = 0;
                 check2 = 0;
             }
             if (s[i] == '*')
             {                                    //   Condition for multiplication
                 check = stack3.pop() * stack3.pop();
                 stack3.push(check);
                 check = 0;
             }
             if (s[i] >= 48 && s[i] <= 57)
             {                  
                 while (s[k] != ' ')  //After every space new value will be pop and in this value geater than 10 also evaluate
                 {
                     val = (val * 10) + (s[k] - 48);
                     k++;         //logic for store value in int variable
                 }
                 stack3.push(val);    
                 val = 0;
                 i = k;
             }

         }
         answer = stack3.pop();
        
         if (stack3.isEmpty())
         {                                        //   Give the answer is after poping stack is empty
             cout << "ANS = " << answer << endl;
         }
         else
         {                                    //   otherwise input is invalid
             cout << "Your input is invalid";
         }

     }
     else if (Case == 2)
     {
    
         int k;
         int val = 0;
         int increment = 1;
         int answer = 0;
         int check = 0; int check2 = 0;
         for (int i = s.size()-1; i >=0; i--)
         {
             k = i;         
             if (s[i] == '+')
             {
                 check = stack3.pop() + stack3.pop();
                 stack3.push(check);
                 check = 0;
             }
             if (s[i] == '-')
             {
                 check = stack3.pop();
                 check2 = stack3.pop();
                 stack3.push(check - check2);
                 check = 0;
                 check2 = 0;
             }
             if (s[i] == '/')
             {
                 check = stack3.pop();
                 check2 = stack3.pop();
                 stack3.push(check / check2);
                 check = 0;
                 check2 = 0;
             }
             if (s[i] == '*')
             {
                 check = stack3.pop() * stack3.pop();
                 stack3.push(check);
                 check = 0;
             }
             if (s[i] >= 48 && s[i] <= 57)
             {
                 
            
                 while (s[k] != ' ') //After every space new value will be pop and in this value geater than 10 also evaluate
                 {
                     val = (s[k] - 48)*increment +(val);
                     k--;                   
                     increment = increment * 10;           //logic for store value in int variable
                 }
                 stack3.push(val);
                 val = 0;
                 increment = 1;
                 i = k;
                 
             }
         }
         answer = stack3.pop();
        
         if (stack3.isEmpty())
         {
             cout << "ANS = " << answer << endl;
         }
         else
         {
             cout << "Your input is invalid";
         }
     }
 }

int main()
{
    int Enter;
    
    string value;
    cout << "NOTE :if your enter postfix or prefix then put space after every operator and operand " << endl;
    cout << "    because if a character is 2 or three digit then space will seperate this" << endl << endl;

    cout << "Enter string :";
    getline(cin, value);
    cout << value << endl;
    cout << "Enter 1 for Expression check " << endl;
    cout << "Enter 2 for Conversion infix to postfix (if you use brackets then use small/round brackets only) " << endl;
    cout << "Enter 3 for Solving Postfix or Prefix " << endl;
    cout << "Enter digit :";
    cin >> Enter;
    if (Enter == 1)
    {
        isBalance(value);
    }
    if (Enter == 2)
    {
        infixToPostfix(value);
    }
    if (Enter == 3)
    {
        int check_case;
        cout << "Enter 1 for postfix OR Enter 2 for prefix ";
        cin >> check_case;
        Evaluate(value, check_case);
    }
  
    return 0;
}    













