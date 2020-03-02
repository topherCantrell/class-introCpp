#include "Board.h"

#include <iostream>
using namespace std;

void Board::clear() {
	for(int x=0;x<9;++x) {
		cells[x] = 0;
	}
}

int Board::getCell(int cellNumber) {
	return cells[cellNumber];
}

bool Board::setCell(int cellNumber, bool isPlayer1) {
	if(isPlayer1) {
		cells[cellNumber] = 1;
	} else {
		cells[cellNumber] = 2;
	}
	return checkForWin();
}

char Board::getPrintCharacter(int contents) {
	if(contents==0) return ' ';
	if(contents==1) return 'X';
	if(contents==2) return 'O';
	return '?';
}

void Board::print() {
	cout << getPrintCharacter(cells[0]) << " | " 
		 << getPrintCharacter(cells[1]) << " | " 
		 << getPrintCharacter(cells[2]) << endl;
	cout << "---------" << endl;
	cout << getPrintCharacter(cells[3]) << " | " 
		 << getPrintCharacter(cells[4]) << " | " 
		 << getPrintCharacter(cells[5]) << endl;
	cout << "---------" << endl;
	cout << getPrintCharacter(cells[6]) << " | " 
		 << getPrintCharacter(cells[7]) << " | " 
		 << getPrintCharacter(cells[8]) << endl;

}

bool Board::checkForWin() {
	for(int p=1;p<3;++p) {
		// Horizontal
		if(cells[0]==p && cells[1]==p && cells[2]==p) return true;
		if(cells[3]==p && cells[4]==p && cells[5]==p) return true;
		if(cells[6]==p && cells[7]==p && cells[8]==p) return true;
		// Vertical
		if(cells[0]==p && cells[3]==p && cells[6]==p) return true;
		if(cells[1]==p && cells[4]==p && cells[7]==p) return true;
		if(cells[2]==p && cells[5]==p && cells[8]==p) return true;
		// Diagonal
		if(cells[0]==p && cells[4]==p && cells[8]==p) return true;
		if(cells[2]==p && cells[4]==p && cells[6]==p) return true;
	}
	return false;
}
