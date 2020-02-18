#ifndef BOARD_H_
#define BOARD_H_

class Board {

	int cells[9];

	// Helper functions
	char Board::getPrintCharacter(int contents);
	bool checkForWin();

public:

	/**
	 * This method clears the board in preparation for a new game.
	 */
	void clear();

	/**
	 * This method returns the contents of the given cell.
	 * @param cellNumber the cell number [0..8]
	 * @return the contents: 0 (empty), 1 (player1), 2 (player2)
	 */
	int getCell(int cellNumber);

	/**
	 * This method registers a players move on the board and returns
	 * true if the move was a win.
	 * @param cellNumber the cell number [0..8]
	 * @return true if the move was a win
	 */
	bool setCell(int cellNumber, bool isPlayer1);

	/**
	 * This method prints the board to the screen in ASCII art.
	 */
	void print();
		
};

#endif