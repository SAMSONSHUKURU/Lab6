/*Samson Shukuru
Fall 22 C++
Lab 6:Binary to Decimal Coversion
write a program that reads binary characters that represent numbers
from a data file and translate them into decimals numbers
*/
#include <iostream>
#include <cmath>
#include<cstdlib>
#include<string>
#include<fstream>
#include<istream>


void Readin(char input, int base10);

void Spaces(char input, int base10, int count, bool Firstdigit, bool BadDigit);

/*void one(char input, int count, int base10, bool Firstdigit);
void two(bool FirstDigit, bool BadDigit, int count); */

using namespace std;
string InputBinary = "c:/users/hp/onedrive - iowa central community college/documents/visual studio 2019/lab6/BinaryIn.dat";
ifstream infile;


int main()
{
	
	char input = ' ';
	int base10 = 0;
	bool Firstdigit = false;
	bool BadDigit = false;
	int count = 0;


	infile.open("c:/users/hp/onedrive - iowa central community college/documents/visual studio 2019/lab6/BinaryIn.dat");
	
	if (!infile)
		cout << "Cant find file!\n";

		Spaces(input,base10,count,Firstdigit,BadDigit);

		return 0;

}

/*void one(char input, int count, int base10, bool Firstdigit)
{
	while (input != '\n' && infile)
	{
		if (!Firstdigit && input == '1' || Firstdigit && (input == '1' || input == '0'))
		{
			count++;
			Firstdigit = true;
			cout << input;
			base10 *= 2;

			if (input == '1')
			{
				base10++;
			}
}
void two(int count, bool Firstdigit, bool BadDigit)
{
	while (infile)
	{
		while (input != '\n' && infile)
		else if (input != ' ' || (input == ' ' && Firstdigit))
		{
			for (int i = 0; i < count; i++)
				cout << '\b';
			cout << "Bad Digit on input\n";
			BadDigit = true;
			infile.ignore(256, '\n');
			break;
		}
	}
}
*/
void Spaces(char input, int base10, int count, bool Firstdigit, bool BadDigit)
{
	while (infile)
	{
		while (input != '\n' && infile)
		{
			//tracks spaces to output bad digits on input
			if (!Firstdigit && input == '1' || Firstdigit && (input == '1' || input == '0'))
			{
				count++;
				Firstdigit = true;
				cout << input;
				base10 *= 2;

				if (input == '1')
				{
					base10++;
				}
			}
			//outputs 'Bad Digit' and back spaces to line up the colums 
			else if (input != ' ' || (input == ' ' && Firstdigit))
			{
				for (int i = 0; i < count; i++)
					cout << '\b';
				cout << "Bad Digit on input\n";
				BadDigit = true;
				infile.ignore(256, '\n');
				break;
			}
		
			infile.get(input);
		}
	// out puts base10, sets [bools] back to false and sets counta nd base10 back to zero
	
			if(!BadDigit)
			cout << "\t\t" << base10 << endl;
			Firstdigit = false;
			BadDigit = false;
			count = 0;
			infile.get(input);
			base10 = 0;
		
	}

}

/*void Readin(char input, int base10)
{
	infile.get(input);
	//reads in characters and calcuates base 2 and sets base10 back to zero
	while (infile)
	{
		//calcuates base10
		while (input != '\n' && infile)
		{
			cout << input;
			base10 *= 2;
			if (input == '1')
			{
				base10++;
			}
			infile.get(input);
		}
		//outputs base 10, grabs a new value and sets base10 back to 0
		cout << "\t\t" << base10 << endl;
		infile.get(input);
		base10 = 0;
	}
		

}*/

