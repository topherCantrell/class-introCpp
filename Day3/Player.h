#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"

class Player {

	bool player;

public:

	/**
	 * This method identifies the player as Player1 or Player2
	 * @param isPlayer1 true if player1 or false if player2
	 */
	void setPlayerNumber(bool isPlayer1);

	/**
	 * This method gets the players next valid move.
	 * @param board the game board for move checking
	 * @return the player's input [0..8]
	 */
	int getMove(Board& board);

	/**
	 * This method prints the "you won" message.
	 */
	void printWin();

};

#endif