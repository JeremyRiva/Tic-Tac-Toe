
#include "Game.h"
#include <string>

void displayMenu();
void userHelp();
int exitGame();
//void invalidSelection();
int initialiseGameMenu();

void setPlayerName(std::string* name);
void nextMove(std::string player, int* coords);
void playerMove(std::string name, int* coords, Game& g, char val);
int checkForWin(Game g, std::string name, char val);

int main()
{
	int startGame{};
	do {
		startGame = initialiseGameMenu();
	} while (startGame == -1);

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


void displayMenu() {
	std::cout << "============ MENU ============\n" << std::endl;
	std::cout << "1. Play Multiplayer game \n\n";
	std::cout << "2. Help \n\n";
	std::cout << "3. Exit \n\n";
	std::cout << "==============================" << std::endl;
}

void userHelp() {
	std::cout << "Enter a row value and a column value between 1-4.\n" \
		"The aim of the game is to score four of a kind in a row. \n\n";
}

int exitGame() {
	char selection;
	std::cout << "Exit game - (y/n)" << std::endl;
	selection = _getch();

	if (selection == 'y' || selection == 'Y') {
		std::cout << "goodbye";
		return -1;
	}
	return 0;
}

/*
void invalidSelection() {
	// https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected
	// stops character values from corrupting selection
	if (std::cin.fail())
	{
		// clear error state
		std::cin.clear();
		// discard 'bad' character(s)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
*/

int initialiseGameMenu()
{
	int selection{};
	displayMenu();
	selection = _getch();

	switch (selection) {
	case '1':
		return 0;
	case '2':
		userHelp();
		return -1;
	case '3':
	{
		if (exitGame() == -1) {
			exit(0);
		}
		return -1;
	}
	default:
	{
		//invalidSelection();
		std::cout << "invalid option - try again" << std::endl;
		return -1;
	}
	}
}

void setPlayerName(std::string* name)
{
	std::cout << *name << " name: ";
	std::getline(std::cin, *name);
	return;
}

void nextMove(std::string player, int* coords)
{
	std::cout << player << "'s turn - row, column: ";
	std::cin >> coords[0] >> coords[1];
	return;
}

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
