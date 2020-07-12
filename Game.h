
#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#define SIZE 4


class Game {

	char gameBoard[SIZE][SIZE]{};
	char user{};    //either 'x' or 'o'

public:

	Game();

	int setPosition(int r, int c, char user);
	char getPosition(int row, int col);
	void printInfo();
	int checkFourInRow(char value);

};

#endif	// _GAME_H_

