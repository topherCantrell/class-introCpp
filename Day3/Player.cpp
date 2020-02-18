#include "Player.h"

#include <iostream>
using namespace std;

void Player::setPlayerNumber(bool isPlayer1) {
	player = isPlayer1;
}

int Player::getMove(Board& board) {
	int move;
	while(true) {
		if(player) {
			cout << "Pick a square Player 1: ";
		} else {
			cout << "Pick a square Player 2: ";
		}
		cin >> move;
		if(move>=1 && move<=9 && board.getCell(move-1)==0) {
			return move-1; // Return 0 to 8
		} 
		
		cout << "Invalid move" << endl;		
	}
}

void Player::printWin() {
	if(player) {
		cout << "You win player 1!" << endl;
	} else {
		cout << "You win player 1!" << endl;
	}
}