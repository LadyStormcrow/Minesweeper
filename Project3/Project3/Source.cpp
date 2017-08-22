#include <iostream>
#include <string>
#include <vector>
#include <time.h>

void draw_board(std::string aArray[]);
void game_logic();
void dynamic_board(); 

int main() {

	//srand(time(NULL)); 

	game_logic();

	return 0;
}

void game_logic() {
	int x = 0;
	int y = 0;
	char player_choice;
	int number_of_bombs = 20;
	bool game_finished = false;

	//actual board
	/*std::string b_array[] = { { '2', '3', '3', '2', 'B', '1', '0', '0', '0' },{ 'B', 'B', 'B', 'B', '2', '1', '1', '0', '0', '0' },{ '2', '3',
		'3', '3', '2', '1', '1', '1', '1', '0' },{ '0', '0', '0', '1', 'B', '1', '1', 'B', '1', '0' },{ '1', '1', '0', '2', '2', '2', '1', '2', '2', '1' },
		{ 'B', '2', '1', '2', 'B', '1', '1', '2', 'B', '1' },{ '1', '2', 'B', '2', '2', '1', '3', 'B', '4', '2' },
		{ '1', '2', '3', '2', '2', 'B', '3', 'B', '4', 'B' },{ '1', 'B', '2', 'B', '3', '2', '3', '2', '4', 'B' },
		{ '1', '1', '2', '1', '2', 'B', '1', '1', 'B', '2' } };_*/

	const int row_count = 10;
	const int col_count = 10;
	int rand_row[row_count];
	int rand_column[col_count];
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int d_up_l = 0;
	int d_up_r = 0;
	int d_down_l = 0;
	int d_down_r = 0;

	char init_board[row_count][col_count] = { { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' } };

	for (int i = 0; i < 10; i++) {
		rand_row[i] = rand() % 10;
		rand_column[i] = rand() % 10;
	}

	for (int j = 0; j < 10; j++) {
		up = 0;
		down = 0;
		left = 0;
		right = 0;
		d_up_l = 0;
		d_up_r = 0;
		d_down_l = 0;
		d_down_r = 0;

		init_board[rand_row[j]][rand_column[j]] = 'B';

		if (rand_column[j] != 0 && rand_row[j] != 0) {
			d_down_l = init_board[rand_row[j] + 1][rand_column[j] - 1] + 1;
			d_up_l = init_board[rand_row[j] - 1][rand_column[j] - 1] + 1;
			init_board[rand_row[j] + 1][rand_column[j] - 1] = (char)d_down_l;
			init_board[rand_row[j] - 1][rand_column[j] - 1] = (char)d_up_l;
		}

		if (rand_column[j] != (col_count - 1) && rand_row[j] != (row_count - 1)) {
			d_down_r = init_board[rand_row[j] + 1][rand_column[j] + 1] + 1;
			d_up_r = init_board[rand_row[j] - 1][rand_column[j] + 1] + 1;
			init_board[rand_row[j] - 1][rand_column[j] + 1] = (char)d_up_r;
			init_board[rand_row[j] + 1][rand_column[j] + 1] = (char)d_down_r;
		}

		if (rand_row[j] != 0) {
			up = init_board[rand_row[j] - 1][rand_column[j]] + 1;
			init_board[rand_row[j] - 1][rand_column[j]] = (char)up;
		}

		if (rand_row[j] != (row_count - 1)) {
			down = init_board[rand_row[j] + 1][rand_column[j]] + 1;
			init_board[rand_row[j] + 1][rand_column[j]] = (char)down;
		}

		if (rand_column[j] != 0) {
			left = init_board[rand_row[j]][rand_column[j] - 1] + 1;
			init_board[rand_row[j]][rand_column[j] - 1] = (char)left;

		}

		if (rand_column[j] != (col_count - 1)) {
			right = init_board[rand_row[j]][rand_column[j] + 1] + 1;
			init_board[rand_row[j]][rand_column[j] + 1] = (char)right;
		}
	}




	//player board (the board to be displayed to the player
	std::string player_board [] = { { '0', '1', '2','3', '4',  '5', '6', '7', '8', '9' },{ '0', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },{ '2', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '3', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },{ '4', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '5', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },{ '6', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '7', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },{ '8', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '9', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' } };

	

	while (!game_finished) {
		system("CLS");

		std::cout << "Welcome to Minesweeper!\n\n\tYou have " << number_of_bombs << " bomb(s) still to find\n\n";

		draw_board(player_board);

		std::cout << "Which row? ";
		std::cin >> y;
		std::cout << "Which column? ";
		std::cin >> x;
		std::cout << "Would you like to (m)ark or (r)eveal or (e)xit? ";
		std::cin >> player_choice;

		if (player_choice == 'e') {
			std::cout << "Sorry to see you go. See you soon!\n\n"; 
			game_finished = true; 
		}

		if (player_board[y + 1][x + 1] == '-') { //if the selected square has not been marked or revealed
			if (player_choice == 'm') { //player choses to mark the box
				if (player_board[y + 1][x + 1] == '-') {
					if (init_board[y][x] == 'B') { //if the marked square is a bomb
						number_of_bombs--; //decrement the amount of bombs
						if (number_of_bombs == 0) { //if all the bombs have been marked 
							std::cout << "\nCongratulations! You found all the bombs!\n";
							game_finished = true; //end the game
						}
					}
					player_board[y + 1][x + 1] = 'X';
				}
			}
			else if (player_choice == 'r') { //player choses to reveal the box 
				if (player_board[y + 1][x + 1] == '-' || player_board[y + 1][x + 1] == 'X') {
					if (init_board[y][x] == 'B') {
						std::cout << "Sorry! You hit a bomb! Game over.\n" << std::endl;
						game_finished = true;
					}
					else {
						player_board[y + 1][x + 1] = init_board[y][x];
					}
				}

			}
		}
		else if (player_board[y + 1][x + 1] == 'X') { //check if the player has marked the selected square
			std::cout << "You have already marked this box! Would you like to reveal it? Type (r) to reveal or (m) to keep marked: ";
			std::cin >> player_choice;
			if (player_choice == 'r') { //if the player reveals the square
				if (player_board[y + 1][x + 1] == '-' || player_board[y + 1][x + 1] == 'X') {
					if (init_board[y][x] == 'B') {
						std::cout << "Sorry! You hit a bomb! Game over.\n" << std::endl;
						game_finished = true;
					}
					else {
						player_board[y + 1][x + 1] = init_board[y][x];
					}
				}
			}
		}
		else if (player_board[y + 1][x + 1] != 'X' && player_board[y + 1][x + 1] != '-') { //if the selected square has been revealed
			std::cout << "You have revealed this square! Try another square.\n\n"; 
		}

		system("pause"); 
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

/*
void dynamic_board() {
	const int row_count = 10; 
	const int col_count = 10; 
	int rand_row[row_count]; 
	int rand_column[col_count]; 
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int d_up_l = 0;
	int d_up_r = 0;
	int d_down_l = 0;
	int d_down_r = 0;

	char init_board[row_count][col_count] = { { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' }, { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	    { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' } };

	for (int i = 0; i < 10; i++) {
		rand_row[i] = rand() % 10; 
		rand_column[i] = rand() % 10; 
	}

	for (int j = 0; j < row_count; j++) {
		up = 0;
		down = 0;
		left = 0;
		right = 0;
		d_up_l = 0;
		d_up_r = 0;
		d_down_l = 0;
		d_down_r = 0;

		init_board[rand_row[j]][rand_column[j]] = 'B';

		if (rand_column[j] != 0 && rand_row[j] != 0) {
			d_down_l = init_board[rand_row[j] + 1][rand_column[j] - 1] + 1;
			d_up_l = init_board[rand_row[j] - 1][rand_column[j] - 1] + 1;
		}

		if (rand_column[j] != (col_count - 1) && rand_row[j] != (row_count - 1)) {
			d_down_r = init_board[rand_row[j] + 1][rand_column[j] + 1] + 1;
			d_up_r = init_board[rand_row[j] - 1][rand_column[j] + 1] + 1;
		}

		if (rand_row[j] != 0) {
			up = init_board[rand_row[j] - 1][rand_column[j]] + 1;	
		}

		if (rand_row[j] != (row_count - 1)) {
			down = init_board[rand_row[j] + 1][rand_column[j]] + 1;
		}
		
		if (rand_column[j] != 0) {
			left = init_board[rand_row[j]][rand_column[j] - 1] + 1;
			
		}
		
		if (rand_column[j] != (col_count - 1)) {
			right = init_board[rand_row[j]][rand_column[j] + 1] + 1;
		}		

		init_board[rand_row[j] - 1][rand_column[j]] = (char)up; 
		init_board[rand_row[j] + 1][rand_column[j]] = (char)down; 
		init_board[rand_row[j]][rand_column[j] - 1] = (char)left; 
		init_board[rand_row[j]][rand_column[j] + 1] = (char)right; 

		init_board[rand_row[j] - 1][rand_column[j] - 1] = (char)d_up_l; 
		init_board[rand_row[j] - 1][rand_column[j] + 1] = (char)d_up_r; 
		init_board[rand_row[j] + 1][rand_column[j] - 1] = (char)d_down_l; 
		init_board[rand_row[j] + 1][rand_column[j] + 1] = (char)d_down_r; 
	}




}*/