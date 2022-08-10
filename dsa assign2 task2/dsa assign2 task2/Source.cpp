#include<iostream>
#include<string>
#include <cmath>
using namespace std;
void decryption(string cipher, string code)
{
	char* enc;
	enc = new char[cipher.size()];
	int count;
	int count2;
	int counter = 0;
	for (int i = 0, k = 0; i < cipher.size(); i++, k++)
	{
		if (int(cipher[i]) == 32)     //for space
		{
			enc[i] = ' ';

		}

		if (k == 1 && counter == 1)        //condition check for retrive code word back
		{
			k--;
			counter--;
		}

		if (int(cipher[i]) >= 65 && int(cipher[i]) <= 90)
		{                                                  // for capital to to small letters
			cipher[i] = int(cipher[i]) + 32;
		}

		if (int(cipher[i]) != 32)        //characters other than space
		{
			                                //main work
			count = (int(code[k]) - 97);        

			enc[i] =abs( count - int(cipher[i]));

			if (abs(count - int(cipher[i])) < 97)
			{                                        //  abs function is for modulus
				count2 = 97 - enc[i] ;
				enc[i] = 123 - count2;
			}
		}		
		if (k == code.size() - 1 && i < cipher.size() - 1)
		{                                                  // condition check for code word
			counter++;
			k = 0;
		}
	}
	for (int i = 0; i < cipher.size(); i++)
	{
		cout << enc[i];
	}

}
void encryption(string messege, string code)
{
	char* enc;
	enc = new char[messege.size()];
	int count;
	int count2;
	int counter = 0;
	for (int i = 0,k=0; i < messege.size(); i++,k++)
	{
		if (int(messege[i]) == 32)
		{                                   //condition for space character
			enc[i] = 32;
			
		} 
		if (int(messege[i]) == 39)
		{                                 //condition for fullstop
			enc[i] = 39;

		}
		if (int(messege[i]) == 46)
		{                                   //condition for postofee
			enc[i] = 46;

		}
		
		if (k==1 && counter==1)
		{                             //condition check for retrive code word back
			k--;
			counter--;
		}  
		
		if (int(messege[i]) >= 65 && int(messege[i]) <= 90)
		{                                                     //condition for uppercase to lower case
			messege[i] = int(messege[i]) + 32;
		}
		if (int(messege[i]) != 32 && int(messege[i]) != 39 && int(messege[i]) != 46)
		{                                //characters other than space,fullstop and postofee.
			                                  
			count =  (int(code[k]) - 97);
			
				enc[i] = int(messege[i]) + count;
			
			if (int(messege[i]) + count > 122)
			{
				count2 = int(enc[i]) - 122;
				enc[i] = 96 + count2;
			}
		}
	
		if (k == code.size() - 1 && i < messege.size() - 1)
		{                                                      //condition check for code word
			counter++;
			k = 0;
		}  
	}
	for (int i = 0; i < messege.size(); i++)
	{
		cout << enc[i];
	}
}
int main()
{
	int enter;
	cout << "Enter 1 for ENCRYPTION and 2 for DECRYPTION : ";
	cin >> enter;
	cin.ignore();
	string messege;
	cout << " Enter Messege : ";
	getline(cin, messege);
	string code;
	cout << "Enter code : ";
	getline(cin, code);
	if (enter == 1)
	{
		encryption(messege, code);
	}
	if (enter == 2)
	{
		decryption(messege, code);
	}
	return 0;
}