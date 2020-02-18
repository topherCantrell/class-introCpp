
#include <iostream>
using namespace std;

// Use a flat array for the board. 0=empty, 1=X, 2=O
int board[] = {0,0,0,   0,0,0,   0,0,0};

/**
 * This fuction maps a board-square state to a printed
 * character.
 * @param contents the contents of the square
 * @return the character representation to print
 */
char getPrintCharacter(int contents) {
	if(contents==0) return ' ';
	if(contents==1) return 'X';
	if(contents==2) return 'O';
	return '?';
}

/**
 * This function prints the tic-tac-toe game board on the screen
 * in ASCII art.
 */
void printBoard() {
	cout << getPrintCharacter(board[0]) << " | " 
		 << getPrintCharacter(board[1]) << " | " 
		 << getPrintCharacter(board[2]) << endl;
	cout << "---------" << endl;
	cout << getPrintCharacter(board[3]) << " | " 
		 << getPrintCharacter(board[4]) << " | " 
		 << getPrintCharacter(board[5]) << endl;
	cout << "---------" << endl;
	cout << getPrintCharacter(board[6]) << " | " 
		 << getPrintCharacter(board[7]) << " | " 
		 << getPrintCharacter(board[8]) << endl;
}

/**
 * This function gets a legal move from the player. The function prints an
 * error and loops until the player enters a valid move.
 * @return the move 0-8
 */
int getLegalMove() {

	int move;

	while(true) {
		cout << "Pick a square: ";
		cin >> move;

		// TODO more detailed reporting here:
		//   - The move is not valid (must be 1-8)
		//   - The square is taken

		if(move>=1 && move<=9 && board[move-1]==0) {
			return move-1; // Return 0 to 8
		} 
		
		cout << "Invalid move" << endl;		
	}
}

/**
 * This method checks the game board for a win configuration. If
 * the board is a "win" the last player to move just won.
 * @return true if won or false if not
 */
bool checkForWin() {
	for(int p=1;p<3;++p) { // Check player 1 then player 2
		// Horizontal
		if(board[0]==p && board[1]==p && board[2]==p) return true;
		if(board[3]==p && board[4]==p && board[5]==p) return true;
		if(board[6]==p && board[7]==p && board[8]==p) return true;
		// Vertical
		if(board[0]==p && board[3]==p && board[6]==p) return true;
		if(board[1]==p && board[4]==p && board[7]==p) return true;
		if(board[2]==p && board[5]==p && board[8]==p) return true;
		// Diagonal
		if(board[0]==p && board[4]==p && board[8]==p) return true;
		if(board[2]==p && board[4]==p && board[6]==p) return true;
	}
	return false;
}

void main() {

	while(true) {
		cout << endl;
		printBoard();
		cout << "Your move player 1 (X)." << endl;
		int m = getLegalMove();
		board[m] = 1;  // 1 for X
		if(checkForWin()) {
			cout << endl << "X wins!" << endl << endl;
			break;
		}
		cout << endl;
		printBoard();
		cout << "Your move player 2 (O)." << endl;
		m = getLegalMove();
		board[m] = 2;  // 2 for O
		if(checkForWin()) {
			cout << endl << "O wins!" << endl << endl;
			break;
		}
	}
	
	printBoard();
	
	system("pause");

}





