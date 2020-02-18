
#include <iostream>
#include <time.h>

using namespace std;

int guessCount;
int myNumber;

void splash() {
	cout << "Welcome to HiLo! I am thinking of a number between 1 and 100." << endl;
	cout << "You guess it!" << endl << endl;
}

int getGuess() {
	cout << "Guess: ";
	int guess;
	cin >> guess;
	guessCount = guessCount + 1;
	return guess;
}

void printHigher() {
	cout << "Higher" << endl;
}

void printLower() {
	cout << "Lower" << endl;
}

void printCorrect() {
	cout << "You got it in " << guessCount << " guesses." << endl;
}

int main() {

	srand(time(0));
	
	splash();

	myNumber = (rand()%100)+1;

	while(true) {

		int guess = getGuess();

		if(guess<myNumber) {
			printHigher();
		}

		if(guess>myNumber) {
			printLower();
		}

		if(guess==myNumber) {
			printCorrect();
			break;
		}

	}

}