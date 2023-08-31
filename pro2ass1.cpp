//file name: proass2.cpp
// Author: Vinceline Bertrand
// email address: bertrandvinceline@gmail.com
// assignment number: 2
//description: a program that calucates amount of dollars in cents and finds
// the least amount of coins possible of equal value when a dollar amount is inputted
// last changed: 06/02/23

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

// declaring constants as local variables to be used throughout
const int QUARTERS = 25;
const int DIMES = 10;
const int NICKELS = 5;
const int PENNIES = 1;

// creating a structure to store num of coins value
struct Money1 {
	int numquarters;
	int numdimes;
	int numnickels;
	int numpennies;
};

// function for each program and a function to enter the dollar amount
double value();
Money1 dispense_cents();
double accept_cents();


int main() 
{

	int choice;
	 double money2;
	do
	{
		cout << endl
			<< " choose 1 to see how much of each each coin is dispensed \n"
			<< "choose 2 to see how much in dollars you have  \n"
			<< "choose 3 to exit program \n";

		cin >> choice;
		if (cin.fail()) {
			cout << "sorry, wrong input. exiting program...";
			exit(1);
		}
		switch (choice)
		{
			// calling function to show how much coins is dispensed
		case 1:
			Money1 coins = dispense_cents();
			cout << "Quarters: " << coins.numquarters << endl;
			cout << "Dimes: " << coins.numdimes << endl;
			cout << "Nickels: " << coins.numnickels << endl;
			cout << "Pennies: " << coins.numpennies;
			break;
		case 2:
			// calling second function to show amount in dollars
			money2 = accept_cents();
			// using setpricision to make sure 1.5 will show as 1.50
			cout << "you have $" << fixed << setprecision(2) << money2;
			break;
		case 3:
			// exit program
			exit(0);
		default:
			// if anything other than what is valid is entered
			cout << "this isn't a valid choice";
			break;
		}
		//the loop continues while choice isn't 3 because 3 exits the program
	} while (choice != 3);
	return 0;
}
// function definition for user input of dollars
double value()
{
	double var;
	cout << "please enter the amount of money you have in dollars" << endl;
	cin >> var;
	return var;
}
// struct function definition to calculate number of coins 
// and return the multiple values: numdimes, numpennies, etc
Money1 dispense_cents()
{
	Money1 money1;
	int cents = static_cast<int>(round (value() * 100));
	money1.numquarters = cents / QUARTERS;
	int store = (cents % QUARTERS);
	money1.numdimes = store / DIMES;
	int remaining = store % DIMES;
	money1.numnickels = remaining / NICKELS;
	money1.numpennies = remaining % NICKELS;

	return money1;
}
// second program function definition 
// storing the value in dollars in the variable called money
// and returning that value into the main function to be used
 double accept_cents()
{
	 int numquarters, numdimes, numnickels, numpennies;
	 cout << "please enter the number of coins you have per denomination" << endl;
	 cout << "Quarters: " << endl;
	 cin >> numquarters;
	 if (cin.fail() || numquarters < 0 ) {
		 cout << "sorry, wrong input. exiting program...";
		 exit(1);
	 }
	 cout << "Dimes: " << endl;
	 cin >> numdimes;
	 if (cin.fail()|| numdimes < 0 ) {
		 cout << "sorry, wrong input. exiting program...";
		 exit(1);
	 }
	 cout << "Nickels: " << endl;
	 cin >> numnickels;
	 if (cin.fail()|| numnickels<0 ) {
		 cout << "sorry, wrong input. exiting program...";
		 exit(1);
	 }
	 cout << "Pennies: " << endl;
	 cin >> numpennies;
	 if (cin.fail()|| numpennies<0 ) {
		 cout << "sorry, wrong input. exiting program...";
		 exit(1);
	 }

	 int store = (numquarters * QUARTERS) + (numdimes * DIMES) + (numnickels * NICKELS) + numpennies;

	 double money = store * pow(10, -2);
	
	 return money;
}