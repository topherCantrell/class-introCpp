#include <iostream>
#include <time.h>

using namespace std;

int main() {

	char playAgain = 'y';

	while(playAgain=='y' || playAgain=='Y') {

		cout << "I am thinking of a number from 1 to 100. You guess it!" << endl;

		srand(time(0));

		int myNumber = rand();
		myNumber = myNumber % 100;
		myNumber = myNumber + 1;

		int myGuess = 0;
		int guessCount = 0;	

		while(myNumber!=myGuess) {
		
			cout << "Your guess: ";
			cin >> myGuess;
			++guessCount;

			if(myGuess<myNumber) {
				cout << "Higher!" << endl;
			}

			if(myGuess>myNumber) {
				cout << "Lower!" << endl;
			}

			if(myGuess==myNumber) {
				cout << "You got it in " << guessCount << " guesses!" << endl;
			}

		}
		
		cout << "Do you want to play again? 'y' or 'n': ";
		cin >> playAgain;

	}


}