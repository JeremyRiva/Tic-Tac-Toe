
#include "Game.h"
#include <string>

//void initialiseGame();
int nextMove(std::string player, int* coords);
std::string namePlayer(std::string* name);

int main()
{
	//initialiseGame();
	std::string name1 = "player 1", name2 = "player 2";
	namePlayer(&name1);
	namePlayer(&name2);

	Game game1;
	int coordinates[2]{};
	game1.printInfo();
	for (int n{}; n < 8; n++)
	{
		int playerMove;
		do {
			nextMove(name1, coordinates);
			playerMove = game1.setPosition(coordinates[0], coordinates[1], 'x');
		} while (playerMove == -1);

		do {
			nextMove(name2, coordinates);
			playerMove = game1.setPosition(coordinates[0], coordinates[1], 'o');
		} while (playerMove == -1);

		game1.printInfo();

		if (game1.fourInRow('x') == -1) {
			std::cout << name1 << " wins!" << std::endl;
			return 0;
		}
		else if (game1.fourInRow('o') == -1) {
			std::cout << name2 << " wins!" << std::endl;
			return 0;
		}
		
	}

	std::cout << "\nIt is a draw!" << std::endl;
}

/*
void initialiseGame() {
	std::cout << "============ MENU ============\n" << std::endl;
	std::cout << "1. Play game \n\n";
	std::cout << "2. Help \n\n";
	std::cout << "3. Exit \n\n";
	std::cout << "==============================" << std::endl;

}
*/

int nextMove(std::string player, int* coords) {

	std::cout << player << "'s turn - row, column: ";
	std::cin >> coords[0] >> coords[1];
	return *coords;
}

std::string namePlayer(std::string* name) {
	std::cout << *name << " name: ";
	std::getline(std::cin, *name);

	return *name;
}