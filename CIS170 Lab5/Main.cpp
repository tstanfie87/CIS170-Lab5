// ---------------------------------------------------------------
// Programming Assignment:	LAB5
// Developer:			          Travis Stanfield
// Date Written:			11/24/2020
// Purpose:				Strings and Pointers: Password Program
// ---------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;
const int SIZE = 80;
const int MIN = 6;
//functio  prototype
int isValid(char pwd[]);

int main()
{
	char password[SIZE];
	while (true)
	{
		cout << "\nPassword requirements :\n";
		cout << "- The password should be at least 6 characters long"<< endl;
		cout << "- The password should contain at least one uppercase"<< endl;
		cout << "- and one lowercase letter."<< endl;
		cout << "- The password should have at least one digit.\n\n";

		cout << "Enter a password: ";
		cin.getline(password, SIZE);
		if (isValid(password) == 1)
		{
			cout << "GREAT VALID PASSWORD!!!\n";
			break;
		}
		else
		{
			cout << "PASSWORD WAS INVALID!!!\n";
		}
	}
	system("pause");


}
int isValid(char pwd[])
{
	//test each character and see if the boolean is set to true
	bool minLength = false;
	bool hasUpper = false;
	bool hasLower = false;
	bool hasDigit = false;
	int length = strlen(pwd);
	if (length >= MIN)
	{
		minLength = true;
	}
	for (int i = 0; i < length; i++)
	{
		if (isupper(*pwd)) //determines if the character is uppercase
			hasUpper = true;
		if (islower(*pwd))//determines if the character is lowercase
			hasLower = true;
		if (isdigit(*pwd))//determines if the character has a digit
			hasDigit = true;
		*pwd++;//increments your array to the next character
	}
	if (minLength == true && hasUpper == true && hasLower == true && hasDigit == true)
		return 1;
	else
		return 0;
}