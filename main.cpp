
#include "Game.h"
#include <string>

//void initialiseGame();

void nextMove(std::string player, int* coords);
void setPlayerName(std::string* name);
void playerMove(std::string name, int* coords, Game& g, char val);
int checkForWin(Game g, std::string name, char val);

int main()
{
	//initialiseGame();
	std::string name1 = "player 1", name2 = "player 2";
	setPlayerName(&name1);
	setPlayerName(&name2);

	Game game;
	int coordinates[2]{};
	game.printInfo();
	for (int n{}; n < 8; n++)
	{
		playerMove(name1, coordinates, game, 'x');

		if (checkForWin(game, name1, 'x') == -1)
			exit(0);

		playerMove(name2, coordinates, game, 'o');

		if (checkForWin(game, name2, 'o') == -1)
			exit(0);
	}

	std::cout << "\nIt is a draw!" << std::endl;
}

//**********************************************************
/*
void initialiseGame() {
	std::cout << "============ MENU ============\n" << std::endl;
	std::cout << "1. Play game \n\n";
	std::cout << "2. Help \n\n";
	std::cout << "3. Exit \n\n";
	std::cout << "==============================" << std::endl;

}
*/
//*************************************************************

void playerMove(std::string name, int* coords, Game& g, char val)
{
	int userInput;
	do {
		nextMove(name, coords);
		userInput = g.setPosition(coords[0], coords[1], val);
	} while (userInput == -1);

	g.printInfo();

	return;
}

int checkForWin(Game g, std::string name, char val)
{
	if (g.checkFourInRow(val) == -1) {
		std::cout << name << " wins!" << std::endl;
		return -1;
	}

	return 0;
}

void nextMove(std::string player, int* coords)
{
	std::cout << player << "'s turn - row, column: ";
	std::cin >> coords[0] >> coords[1];
	return;
}

void setPlayerName(std::string* name)
{
	std::cout << *name << " name: ";
	std::getline(std::cin, *name);
	return;
}