
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

int CandyGame(int candies, int moves) {
	if (candies <= 0 || candies >= 10000 && moves != -1) {
		cout << "Number of Candies must be greater than 0 and no more than 10000" << endl;
		cout << "How many Candies are you starting with?" << endl;
		cin >> candies;
		CandyGame(candies, moves);
	}
	else {
		if (moves == 20) {
			cout << "Searching for a solution within 20 moves..." << endl;
		}
		if (candies == 17 && moves != -1) {
			cout << "Found solution.  I have exactly 17 Candies, with " << moves << " moves left." << endl;
			return 0;

		}
		if (candies % 2 == 0 && moves != -1 && candies != 46 && candies > 17) {
			int Evencandies = candies / 2;
			--moves;
			if (moves > 0) {
				if (CandyGame(Evencandies, moves)==0) {
					cout << "Reduce " << candies << " by half to get " << Evencandies << endl;
					return 0;
				}
			}
		}
		if (candies % 3 == 0 && moves !=-1) {
			int Oddcandies = candies + candies / 3;
			--moves;
			if (moves > 0) {
				if (CandyGame(Oddcandies, moves) == 0) {
					cout << "With " << candies << " add 1/3 of candies to get " << Oddcandies << endl;
					return 0;
				}
			}
		}
		if (moves != -1) {
			int Misccandies = candies + 23;
			--moves;
			if (moves > 0) {
				if (CandyGame(Misccandies, moves) == 0) {
					cout << "With " << candies << " add 23 to get" << Misccandies << endl;
					return 0;
				}
			}


		}
	}

	return 1;
}

int KeepPlaying(char answer) {
	if (answer == 'n' || answer == 'N') {
		return -1;
	}
	if (answer == 'y' || answer == 'Y') {
		return 0;
	}
	else {
		cout << "Please enter Y/y or N/n" << endl;
		char newanswer;
		cin >> newanswer;
		KeepPlaying(newanswer);
	}
}