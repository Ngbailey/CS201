//Nathan Gregorian Bailey
//Section 0002
//Program # 3
//Created March 3rd, 5:30PM
//Due March 6th 2022, 11:59PM


#include<iostream>
#include<cmath>
#include<string>
#include <iomanip>
#include <vector>
#include <time.h>
#include <algorithm> 
#include <fstream>

using namespace std;

void printCustomersData(string Last[], string First[], int ID[], double saving[], double checking[])
{
	cout << endl << endl;
	cout << setfill(' ') << setw(15) << "Last" << setw(15) << setfill(' ') << "First" << setw(15) << setfill(' ') << "ID" << setw(25) << setfill(' ') << "Savings Account" << setw(25) << setfill(' ') << "Checkings Account" << endl;
	cout << endl;
	for (int i =0; i < 10; ++i) 
	{
		cout << setfill(' ') << setw(15) << Last[i] << setfill(' ') << setw(15) << First[i] << setfill(' ') << setw(15) << ID[i] << setfill(' ') << setw(20) << saving[i] << setfill(' ') << setw(25) << checking[i] << endl;
	}
	cout << endl << endl;
}


void printNames(string First[], string Last[], const int AS)
{
	cout << endl << endl;
	cout << setfill(' ') << setw(15) << "First" << setw(15) << setfill(' ') << "Last" << setw(15) << setfill(' ') << endl << endl;
	for (int i=9; i >= 0; --i) 
	{
		for (int j=0; j<i;++j) 
		{
			if (First[j+1] > First[j]) 
			{
				swap(First[j], First[j + 1]);
				swap(Last[j], Last[j + 1]);
			}
			if (First[j] == First[j + 1]) 
			{
				if (Last[j+1] > Last[j]) 
				{
					swap(First[j], First[j + 1]);
					swap(Last[j], Last[j + 1]);
				}
			}
		}
		cout << setfill(' ') << setw(15) << First[i] << setw(15) << setfill(' ') << Last[i] << setw(15) << setfill(' ') << endl;
	}
	cout << endl;
	cout << "**************************************" << endl;
	cout << "Total Number of Customers is: " << AS << endl;
	cout << "**************************************" << endl << endl;

}


void printBankTotal(int ID[], double saving[], double checking[])
{
	double savingsTotal = 0;
	double checkingsTotal = 0;
	double bankTotal = 0;
	cout << endl << endl;
	cout << setw(15) << setfill(' ') << "ID" << setw(25) << setfill(' ') << "Savings Account" << setw(25) << setfill(' ') << "Checkings Account" << endl;
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << setfill(' ') << setw(15) << ID[i] << setfill(' ') << setw(20) << saving[i] << setfill(' ') << setw(25) << checking[i] << endl;
	}
	for (int i = 0; i < 10; ++i) 
	{
		savingsTotal += saving[i];
		checkingsTotal += checking[i];
	}
	bankTotal = checkingsTotal + savingsTotal;
	cout << endl << endl;
	cout << "*******************************************" << endl;
	cout << "The total in all customers savings accounts is: $" << savingsTotal << endl;
	cout << "The total in all customers checking accounts is: $" << checkingsTotal << endl;
	cout << "The total amount in the bank is: $" << bankTotal << endl;
	cout << "*******************************************" << endl << endl;
}






int main() 
{
	ifstream inStream;
	const int AS = 10;
	int ID[AS];
	string First[AS];
	string Last[AS];
	double saving[AS];
	double checking[AS];
	char checker;
	int numChecker = -1;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		cout << "Input file opening failed\n";
		exit(1);
	}
	for (int i = 0; i < AS; ++i) 
	{
		inStream >> ID[i] >> First[i] >> Last[i] >> saving[i] >> checking[i];
	}
	inStream.close();
	cout << "Welcome to the KC Banking Accounts program" << endl << endl;
	while (numChecker == -1)
	{
		cout << "Press 1 to print customer information" << endl;
		cout << "Press 2 to print all customer names" << endl;
		cout << "Press 3 to print the  total  amount  of  money  for  each  customer  and  the  Bank's total amount." << endl;
		cout << "Press q/Q to quit" << endl;

		cin >> checker;

		if (checker == 'q' || checker == 'Q') {
			numChecker = 0;
			cout << endl << endl;
			cout << "Thank you for using the KC Banking Account Program" << endl << "Have a good day" << endl << "Goodbye!" << endl;
			break;
		}
		else if (checker == '1') {
			printCustomersData(Last, First, ID, saving, checking);
		}
		else if (checker == '2') {
			printNames(First, Last, AS);
		}
		else if (checker == '3') {
			printBankTotal(ID, saving, checking);
		}
		else {
			cout << endl;
			cout << "Invalid Input, please input '1', '2', '3', or 'q/Q'." << endl;
			cout << endl;
		}

	}





}