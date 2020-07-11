
#include <iostream>
#define SIZE 4

class Game {
	char gameBoard[SIZE][SIZE]{};
	char user{};    //either 'x' or 'o'
public:

	Game()
	{
		for (int i{}; i < SIZE; i++) {
			for (int j{}; j < SIZE; j++) {
				gameBoard[i][j] = '-';
			}
		}
	}

	int setPosition(int r, int c, char user)
	{
		if (r <= 0 || r > SIZE || c <= 0 || c > SIZE) {
			std::cout << "out of range - try again" << std::endl;
			return -1;
		}

		int row = r - 1;
		int col = c - 1;

		if (gameBoard[row][col] == '-') {
			gameBoard[row][col] = user;
			return 0;
		}
		else {
			std::cout << "position has already been taken - try again" << std::endl;
			return -1;
		}
	}

	char getPosition(int row, int col)
	{
		return gameBoard[row][col];
	}

	void printInfo()
	{
		for (int i{}; i < SIZE; i++) {
			std::cout << "\t";
			for (int j{}; j < SIZE; j++) {
				std::cout << gameBoard[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	int fourInRow(char value) {
		for (int i{}; i < SIZE; i++)
		{
			int rows{}, cols{}, diagR{}, diagL{};
			for (int j{}; j < SIZE; j++)
			{
				// checks rows
				if (gameBoard[i][j] == value) {
					rows++;
					if (rows == 4)
						return -1;
				}
				// checks columns
				if (gameBoard[j][i] == value) {
					cols++;
					if (cols == 4)
						return -1;
				}
				// checks right diagonal
				if (gameBoard[j][j] == value) {
					diagR++;
					if (diagR == 4)
						return -1;
				}
				// checks left diagonal
				if (gameBoard[3][0] == value && gameBoard[2][1] == value && gameBoard[1][2] == value && gameBoard[0][3] == value) {
					diagL = 4;
					return -1;
				}
			}
		}
		return 0;
	}
};