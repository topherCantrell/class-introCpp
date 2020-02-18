#include <iostream>
using namespace std;

void printBoard(int* board) {

	char print[5] = {' ', 'x', 'o', 'X', 'O'};

	// 3 rows to print
	for(int y=0;y<3;++y) {

		// 3 columns to print
		for(int x=0;x<3;++x) {

			cout << print[*board];
			
			// Print a divider line between columns 0 and 1
			if(x==0 || x==1) {
				cout << "|";
			}
			// Next square
			++board;
		}		
		// Print a line return
		cout << endl;

		// Print a divider line between rows 0 and 1
		if(y==0 || y==1) {
			cout << "-+-+-" << endl;
		}
	}

	// Blank row at bottom of board
	cout << endl;	
}

bool checkLine(int* board, int start, int offset, int winMark) {
	if(board[start]==0) return false;
	if(board[start]==board[start+offset] && board[start]==board[start+offset*2]) {
		board[start] = winMark;
		board[start+offset] = winMark;
		board[start+offset*2] = winMark;
		return true;
	}
	return false;
}
bool checkForWin(int* board, int winMark) {
	// Check the rows
	if(checkLine(board,0,1,winMark)) return true;
	if(checkLine(board,3,1,winMark)) return true;
	if(checkLine(board,6,1,winMark)) return true;
	// Check the columns
	if(checkLine(board,0,3,winMark)) return true;
	if(checkLine(board,1,3,winMark)) return true;
	if(checkLine(board,2,3,winMark)) return true;
	// Check the diagonals
	if(checkLine(board,0,4,winMark)) return true;
	if(checkLine(board,2,2,winMark)) return true;
	// No winning lines. 
	return false;
}

void printDirections() {
	cout << "2 player TIC TAC TOE" << endl << endl;
	cout << "Square numbering:" << endl;
	cout << " 1|2|3" << endl
		 << " -+-+-" << endl
		 << " 4|5|6" << endl
		 << " -+-+-" << endl
		 << " 7|8|9" << endl;
}

bool turnPlayer(int* board, int marker, int winMarker, char name) {
	// The current player's move
	int move;

	// Show the board
	cout << endl;
	printBoard(board);

	// Loop until we get a good move
	while(true) {
		// Get the move
		cout << "Enter a square number player " << name << " :";
		move = 0;
		cin >> move;
		// Make sure the move is in range and the square is empty
		if(move>0 && move<10 && board[move-1]==0) {
			// Move is OK ... break out of input loop
			break;
		}
		// Tell player to try again and go back for another input
		cout << "Invalid move." << endl;
	}

	// Place the marker on the board
	board[move-1] = marker;
	// Check for a win
	if(checkForWin(board,winMarker)) {
		cout << endl << endl;
		printBoard(board);
		cout << "You win player " << name << " !!" << endl;
		return true;
	}

	// Not a win
	return false;
}


int main() {

	// Initialize board to empty
	int board[9] = {0,0,0,  0,0,0,  0,0,0};

	// Print directions
	printDirections();	

	// Enless play loop (we "return" on a win)
	while(true) {
		
		bool win = turnPlayer(board,1,3,'X');
		if(win) return 0;

		win = turnPlayer(board,2,4,'O');
		if(win) return 0;

	}
	
}