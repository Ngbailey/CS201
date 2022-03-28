//Nathan Gregorian Bailey
//Section 0002
//Program # 1
//Created Febuary 1st 2022, 10:31PM
//Due febuary 6th 2022, 11:59PM


#include<iostream>
#include<cmath>
#include<string>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Welcome to KC Cookies" << endl; // Menu
	cout <<" " << endl;
	cout << "We offer 3 different packs of Cookies\n" << endl;
	cout << "4 Pack Box      $13.20" << endl;
	cout << "6 Pack Box      $19.49" << endl;
	cout << "Party Box '12'  $34.08" << endl;
	cout << " " << endl;
	int checker1 = -1;
	int userPackChoice;
	int amountOne = 0;
	int amountTwo = 0;
	int amountThree = 0;
	double totalPurchase = 0;
	char cont;

	while (checker1 == -1) { // repeat order loop

		cout << "What would you like to order today?\n\n1 ==> 4 - Pack Cookies\n2 ==> 6 - Pack Cookies\n3 ==> Party Box(12 - Pack Cookies)\nPlease enter '1 or 2 or 3' to proceed" << endl;
		
		cin >> userPackChoice;
		if ((userPackChoice == 1) || (userPackChoice == 2) || (userPackChoice == 3)) {
			checker1 = 0;
			if ((userPackChoice == 1)) {
				cout << "How many packs do you want?\n" << endl;
				cin >> amountOne;
				cout << "You ordered: " << amountOne << " 4-Pack Cookies\n" << endl;
				totalPurchase += amountOne * 13.20;

			}
			else if ((userPackChoice == 2)) {
				cout << "How many packs do you want?\n" << endl;
				cin >> amountTwo;
				cout << "You ordered: " << amountTwo << " 6-Pack Cookies\n" << endl;
				totalPurchase += amountTwo * 19.49;

			}
			else if ((userPackChoice == 3)) {
				cout << "How many packs do you want?\n" << endl;
				cin >> amountThree;
				cout << "You ordered: " << amountThree << " 12-Pack Cookies\n" << endl;
				totalPurchase += amountThree * 34.08;

			}
		}
		else { // not required but thought would be fun to have a little bit of human error proofing, wonky at the moment
			checker1 = -1;
			cout << "\nPlease enter 1, 2, or 3.\n" << endl;
			cout << " " << endl;
			continue;
		}
		if (checker1 == 0) { // issue where if they choose Y/y but then do not pick 1,2 or 3 instead of requesting them to pick 1,2, or 3 it goes on an infite loop repeating the menu
			cout << "Do you want to add anything else? Y/y or N/n" << endl;
			cin >> cont;
			if ((cont == 'y') || (cont == 'Y')) {
				checker1 = -1;
				continue;


			}
			else {
				cout << fixed << setprecision(2);
				cout << " " << endl;
				cout << "Total of your order is $" << totalPurchase << endl;
			}

		}

	}


}