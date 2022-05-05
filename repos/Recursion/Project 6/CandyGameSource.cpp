#include "CandyGameHeader.h"
using namespace std;

int main() {
	int userCandies;
	int moves = 20;
	int checker = 0;
	char PlayAgain;
	while (checker == 0) {
		cout << "How many Candies are you starting with?" << endl;
		cin >> userCandies;
		if (CandyGame(userCandies, moves) != 0) {
			cout << "No solution found within 20 moves. Sorry." << endl;
			}
		cout << "Would you like to try again [Y/N]?" << endl;
		cin >> PlayAgain;
		checker = KeepPlaying(PlayAgain);
	}













	return 0;
}