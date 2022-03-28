//Nathan Gregorian Bailey
//Section 0002
//Program # 2
//Created Febuary 16th 2022, 6:32AM
//Due Febuary 22nd 2022, 11:59PM


#include<iostream>
#include<cmath>
#include<string>
#include <iomanip>
#include <vector>
#include <time.h>
#include <algorithm> 

using namespace std;
//starting deck
void liveCards(vector<int>& deck) {
	cout << endl;
	cout << "Live Cards: ";
	for (int i = 0; i < deck.size(); ++i) {
		cout << deck[i] << " ";
	}
}
// forgot to add sorting
void deaddeckCards(vector<int>& deadCards, int& currentScore) {
	cout << "Current Score: " << currentScore << endl;
	cout << "Dead Cards: ";
	for (int i = 0; i < deadCards.size(); ++i) {
		if (deadCards[i] > 0) {
			cout << deadCards[i] << " ";
		}
	}
}
//this is Code i wrote for zyBook to sort in descending order repurposed for this program
void deaddeckCardsfixed(vector<int>& deadCards, int& deadplaceholder, int& currentScore) {
	int i;
	int j;
	int temp;
	int smallestIndex;
	int z;

	for (i = 0; i < deadplaceholder - 1; ++i) {
		smallestIndex = i;
		for (j = i + 1; j < deadplaceholder; ++j) {
			if (deadCards[j] < deadCards[smallestIndex]) {
				smallestIndex = j;
			}
		}
		temp = deadCards[i];
		deadCards[i] = deadCards[smallestIndex];
		deadCards[smallestIndex] = temp;

	}
	for (z = 1; z < deadplaceholder - 1; ++z) {
		smallestIndex = z;
		for (j = z + 1; j < deadplaceholder; ++j) {
			if (deadCards[j] < deadCards[smallestIndex]) {
				smallestIndex = j;
			}
		}
		temp = deadCards[z];
		deadCards[z] = deadCards[smallestIndex];
		deadCards[smallestIndex] = temp;
	}
	cout << "Current Score: " << currentScore << endl;
	cout << "Dead Cards: ";
	for (int i = 0; i < deadCards.size(); ++i) {
		if (deadCards[i] > 0) {
			cout << deadCards[i] << " ";
			}
		}


}


int main() 
{
	vector<int> deck = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int currentScore = 0;
	vector<int> deadCards(16);
	bool gameFinished = false;
	int deckSizeIndex = 16;
	int cardTransfer;
	int deadplaceholder =0;
	char userInput;
	int takeChecker = 0;
	srand(time(NULL));
	while (!gameFinished) {
		
		deaddeckCardsfixed(deadCards, deadplaceholder, currentScore);

		liveCards(deck);
		
		cout << endl;
		cout << "Next Card: ";
		for (int i = 0; i < deckSizeIndex+1;++i) {
			if (deck.empty()) {
				break;
			
			}
			userInput = 'w';
			int randomNumber = ((rand() % deckSizeIndex));
			cout << deck[randomNumber];
			deckSizeIndex = deckSizeIndex - 1;
			cardTransfer = deck[randomNumber];
			deadCards[deadplaceholder] = cardTransfer;
			++deadplaceholder;
			deck.erase(deck.begin() + randomNumber);
			if ((takeChecker > cardTransfer)) {
				cout << " DEAD " << endl << endl;
				break;
			}
			cout << endl << "Take it [T] or Leave it [L]? " << endl;
			cin >> userInput;
			if (userInput == 't') {
				takeChecker = cardTransfer;
				currentScore += cardTransfer;
				cout << endl;

				break;
			}
			if (userInput == 'l') {
				cout << endl;
				break;
			}
			
		
		}
		if (deadplaceholder >= 16) {
			gameFinished = true;
			
		}
	}
	cout << "Final score is: " << currentScore << endl;
}