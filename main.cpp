
#include "Game.h"
#include <string>

//void initialiseGame();

std::string setPlayerName(std::string* name);
int playerMove(std::string name, int *coords, Game &g, char val);
int nextMove(std::string player, int *coords);

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
		playerMove(name2, coordinates, game, 'o');
		
		if (game.checkFourInRow('x') == -1) {
			std::cout << name1 << " wins!" << std::endl;
			return 0;
		}
		else if (game.checkFourInRow('o') == -1) {
			std::cout << name2 << " wins!" << std::endl;
			return 0;
		}
		
	}

	std::cout << "\nIt is a draw!" << std::endl;
}

int playerMove(std::string name, int *coords, Game &g, char val) {

	int userInput;
	do {
		nextMove(name, coords);
		userInput = g.setPosition(coords[0], coords[1], val);
	} while (userInput == -1);

	g.printInfo();

	return 0;
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
int nextMove(std::string player, int *coords) {

	std::cout << player << "'s turn - row, column: ";
	std::cin >> coords[0] >> coords[1];
	return *coords;
}

std::string setPlayerName(std::string* name) {
	std::cout << *name << " name: ";
	std::getline(std::cin, *name);

	return *name;
}