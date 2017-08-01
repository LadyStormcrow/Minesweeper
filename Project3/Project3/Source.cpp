#include <iostream>
#include <string>

void draw_board(std::string aArray[]);
void game_logic();

int main() {

	game_logic();

	system("pause");

	return 0;
}

void game_logic() {
	int x = 0;
	int y = 0;
	char player_choice;
	int number_of_bombs = 20;
	bool game_finished = false;

	std::cout << "Welcome to Minesweeper!\n\nYou have " << number_of_bombs << " bomb(s) still to find\n";

	//actual board
	std::string board_array[] = { { '2', '3', '3', '2', 'B', '1', '0', '0', '0' },{ 'B', 'B', 'B', 'B', '2', '1', '1', '0', '0', '0' },{ '2', '3',
		'3', '3', '2', '1', '1', '1', '1', '0' },{ '0', '0', '0', '1', 'B', '1', '1', 'B', '1', '0' },{ '1', '1', '0', '2', '2', '2', '1', '2', '2', '1' },
		{ 'B', '2', '1', '2', 'B', '1', '1', '2', 'B', '1' },{ '1', '2', 'B', '2', '2', '1', '3', 'B', '4', '2' },
		{ '1', '2', '3', '2', '2', 'B', '3', 'B', '4', 'B' },{ '1', 'B', '2', 'B', '3', '2', '3', '2', '4', 'B' },
		{ '1', '1', '2', '1', '2', 'B', '1', '1', 'B', '2' } };

	//player board (the board to be displayed to the player
	std::string player_board[] = { { '0', '1', '2','3', '4',  '5', '6', '7', '8', '9' },{ '0', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },{ '2', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '3', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },{ '4', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '5', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },{ '6', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '7', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },{ '8', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '9', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' } };

	

	while (!game_finished) {
		draw_board(player_board);

		std::cout << "Which row? ";
		std::cin >> y;
		std::cout << "Which column? ";
		std::cin >> x;
		std::cout << "Would you like to (m)ark or (r)eveal? ";
		std::cin >> player_choice;

		if (player_choice == 'm') {
			if (board_array[y][x] == 'B') {
				number_of_bombs--;
				if (number_of_bombs == 0) {
					std::cout << "\nCongratulations! You found all the bombs!";
				}
			}
			player_board[y + 1][x + 1] = 'X';
		}
		else if (player_choice == 'r') {
			if (board_array[y][x] == 'B') {
				std::cout << "Sorry! You hit a bomb! Game over." << std::endl;
				game_finished = true;
			}
			else {
				player_board[y + 1][x + 1] = board_array[y][x];
			}
		}
	}

}

void draw_board(std::string aArray[]) {

	for (int i = 0; i < 11; i++) {
		
		for (int j = 0; j < 11; j++) {
			if ((i == 0) && (j == 0)) {
				std::cout << "   ";
			}
			std::cout << aArray[i][j] << "  ";
		}
		std::cout << "\n";
	}


}