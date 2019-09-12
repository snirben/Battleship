/*Assignment: 2
Campus : Beer Sheva
	Author : Snir Ben Yosef, ID : 307908699
	*/
#include "game.h"
#include "battleship.h"
#include <ctime>
#include <string>

int game::cells_taken;
game::game()
{
	cout << "How many battleships do you want to place on board? " << endl; //output
	cin >> number_of_ships; // input
	if (number_of_ships < 1 || number_of_ships >5) //checks how much the user picked
		number_of_ships = 1;
	if (number_of_ships == 1)
		cells_taken = 5;
	if (number_of_ships == 2)
		cells_taken = 9;
	if (number_of_ships == 3)
		cells_taken = 12;
	if (number_of_ships == 4)
		cells_taken = 14;
	if (number_of_ships == 5)
		cells_taken = 17;

}

game::~game()
{
	delete[] ships;
}

void game::ClearBoard()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = '_';
		}
	}
}

int game::CheckPlace(int l, int r, int dir, int size)
{
	// Start of checking the up dirction
	int flag = 0,i;
	if (dir == 1) {
		for (i = 0; i < size; i++, l--) {
			
			if (l < 0 || l>9)
				flag = 1;


			if (l == 0 && r >= 0) {
				if (i == 0)
					flag = 1;
				if (i != 0 &&(board[l][r] != '_'|| board[l][r-1] != '_'|| board[l][r+1] != '_'|| board[l+1][r-1] != '_'|| board[l+1][r+1] != '_')) {
					flag=1;

				}

			}
			if (dir == 1 && r != 0 && l != 9 && r != 9) {
				if (i == 0 && (board[l][r] != '_' || board[l][r - 1] != '_' || board[l + 1][r] != '_' || board[l][r + 1] != '_'  || board[l + 1][r - 1] != '_' || board[l + 1][r + 1] != '_' || board[l - 1][r -1] != '_' || board[l - 1][r ] != '_' || board[l - 1][r + 1] != '_'))
					flag = 1;
				if (i!=0 &&(board[l][r] == '_' || board[l][r - 1] != '_' ||  board[l][r + 1] != '_' || board[l + 1][r - 1] != '_' || board[l + 1][r + 1] != '_' || board[l - 1][r - 1] != '_' || board[l - 1][r] != '_' || board[l - 1][r + 1] != '_'))
					flag=1;
			}



			if (dir == 1 && r == 0 && l != 0){
				if(i==0 && l!=9 &&(board[l][r] != '_' || board[l][r + 1] != '_' || board[l - 1][r] != '_' || board[l + 1][r + 1] != '_' || board[l - 1][r + 1] != '_' || board[l + 1][r] != '_'))
				flag = 1;
				if (i != 0 && l!=9 && (board[l][r] != '_' || board[l][r + 1] != '_' || board[l - 1][r] != '_' || board[l + 1][r + 1] != '_' || board[l - 1][r + 1] != '_'))
					flag = 1;
			}

			

			if (dir == 1 && r == 9 && l != 0) {
				if(i==0 && l!=9 && (board[l][r]!= '_'|| board[l][r - 1] != '_' || board[l - 1][r - 1] != '_' || board[l + 1][r - 1] != '_' || board[l + 1][r] != '_' || board[l - 1][r] != '_')) {
				flag = 1;
			}
				if(i != 0 && l != 9 && (board[l][r - 1] != '_' || board[l - 1][r - 1] != '_' || board[l + 1][r - 1] != '_' || board[l - 1][r] != '_'))
					flag=1;
			}
			
			if (dir == 1 && l == 9 && r!=0) {
				if ( r != 9 && (board[l][r - 1] != '_'|| board[l - 1][r - 1] != '_' || board[l - 1][r] != '_' || board[l - 1][r+1] != '_' || board[l][r+1] != '_')) {
					flag = 1;
				}
	
			}
			if (r == 0 && l == 9) {
				if (board[l][r] != '_' || board[l][r + 1] != '_' || board[l - 1][r + 1] != '_' || board[l - 1][r] != '_')
					flag = 1;
			}
			if (r == 9 && l == 9) {
				if (board[l][r] != '_' || board[l][r - 1] != '_' || board[l - 1][r - 1] != '_' || board[l - 1][r] != '_')
					flag = 1;
			}
			
		}
	}

	// Start of checking the right dirction
	
	if (dir == 0) {
		for (i = 0; i < size; i++, r++) {
			
			if (r < 0 || r>9)
				flag = 1;
			if (dir == 0 && r != 0 && l != 9 && r != 9 && l != 0) {
				if (i == 0 && (board[l][r] != '_' || board[l + 1][r] != '_' || board[l - 1][r] != '_' || board[l][r - 1] != '_' || board[l][r + 1] != '_' || r >= 0 || board[l + 1][r - 1] != '_' || board[l + 1][r + 1] != '_' || board[l - 1][r - 1] != '_' || board[l - 1][r + 1] != '_'))
					flag = 1;
				if (i != 0 && (board[l][r] == '_' || board[l][r - 1] == '_' || board[l][r + 1] == '_' || l >= 0 || board[l + 1][r - 1] == '_' || board[l + 1][r + 1] == '_'))
					flag = 1;
			}
			if (dir == 0 && r == 0 && l!=0 && l!=9) {
				if (i == 0 && (board[l][r] != '_' || board[l + 1][r + 1] != '_' || board[l - 1][r] != '_' || board[l][r + 1] != '_' || board[l - 1][r + 1] != '_' || board[l + 1][r] != '_'))
					flag = 1;
				if (i != 0 && (board[l][r] != '_' || board[l + 1][r + 1] != '_' || board[l - 1][r] != '_' || board[l][r + 1] != '_' || board[l - 1][r + 1] != '_'))
					flag = 1;
			}
			if (dir == 0 && i == 0 && l == 9 && r != 9) {
				if (board[l - 1][r] != '_' || board[l - 1][r + 1] != '_' || board[l][r + 1] != '_' || board[l][r - 1] != '_' || board[l - 1][r - 1] != '_') {
					flag = 1;
				}
				if (i >= 1 && (board[l - 1][r] != '_' || board[l - 1][r + 1] != '_' || board[l][r + 1] != '_' || board[l - 1][r - 1] != '_'))
					flag = 1;
			}


			if (dir == 0 && i == 0 && l <= 9 && r == 9)
				flag = 1;

			if (dir == 0 && l == 0 && r >= 0 && r != 9) {
				if (i == 0 && (board[l][r] != '_' || board[l + 1][r + 1] != '_' || board[l][r + 1] != '_' || board[l + 1][r] != '_' || board[l][r - 1] != '_'|| board[l + 1][r-1] != '_'))
					flag = 1;

				if (i != 0 && (board[l][r] != '_' || board[l + 1][r + 1] != '_' || board[l][r + 1] != '_' || board[l + 1][r] != '_'|| board[l + 1][r - 1] != '_'))
					flag = 1;
			}
		}
	}



	return flag;

}



void game::BuildBoard()
{
	int flag = 0;
	int shipsize;
	int j, dir, l, r, k = 5;;
	if (number_of_ships >= 1 && number_of_ships <= 5)
		ships = new battleship[number_of_ships];
	srand(time(0));
	for (int i = 0; i < number_of_ships; i++, k--) {
		dir = rand() % 2;
		l = rand() % 10;
		r = rand() % 10;
		
		ships[i].setsize(k);
		if (k == 1)
			ships[i].setsize(3);

		shipsize = ships[i].getsize();
		while (flag == 0) {
			if (CheckPlace(l, r, dir, shipsize-1) == 0)
				flag = 1;
			if (flag == 0) {
				dir = rand() % 2;
				l = rand() % 10;
				r = rand() % 10;
			}
		}

		for (j = 0; j < shipsize; j++) {
				
					board[l][r] = 'S';

					if (dir == 1 && j != 0) {
						l--;
						board[l][r] = 'S';

					}


					if (dir == 0 && j != 0) {
						r++;
						board[l][r] = 'S';


					}
				}

			
		
			flag = 0;
	}




}

void game::PrintBoard()
{
	int flag=0;
	cout << " ";
	cout << "  ";
	for (char i = 65; i < 75; i++) {
		cout << i << "  ";
	}
	cout << endl;
	for (int i = 1; i < 11; i++) {
		if(i== 10)
			cout << i << " ";
		if(i!= 10)
		cout << i<<"  " ;
		for (int k = 0; k < 10; k++) {
			if (board[i-1][k] == 'S') {
			cout << "_"<<"  ";
			 flag = 1;
			}
			if(flag==0)
			cout << board[i-1][k] << "  ";
			flag = 0;
		}
		cout << endl << endl;
	}
}

void game::PrintOriginalBoard()
{

		cout << " ";
		cout << "  ";
		for (char i = 65; i < 75; i++) {

			cout << i << "  ";
			
		}
		cout << endl;
		for (int i = 1; i < 11; i++) {
			if (i != 10)
			cout << i<<"  ";
			if (i == 10)
				cout << i << " ";
			for (int k = 0; k < 10; k++) {
				cout << board[i-1][k] << "  ";
			}
			cout << endl << endl;
		}

	

	}

void game::CheckHit(int l, int r)
{
	if (board[l][r] == '@' || board[l][r] == 'X') {
		cout << "You Already Pick it!"<<endl;
		return;
}
	if (board[l][r] == 'S') {
		board[l][r] = '@';
		cout << "Hit!" << endl;
		cells_taken--;
	}
	if (board[l][r] == '_') {
		board[l][r] = 'X';
		cout << "You Miss!" << endl;
	
	}
	}

void game::CheckSunk(int l, int r)
{
	int flag = 0, flag2 = 0;
	if (board[l][r] == '@' && (board[l + 1][r] == '@' || board[l - 1][r] == '@')) {
		l++;
		for (int i = 0; i < 5; i++, l++) {
			if (board[l][r] == 'S')
				break;
			if (board[l][r] != 'S' && board[l][r] != '@')
				flag = 1;

			if (board[l - (i + 2)][r] == 'S')
				break;
			if (i == 0 && (board[l - (i + 2)][r] != 'S' || board[l - (i + 2)][r] != '@'))
				flag2 = 1;
			if (i != 0 && (board[l - (i + 2)][r] != 'S' || board[l - (i + 2)][r] != '@'))
				flag2 = 1;
			if (flag == 1 && flag2 == 1) {
				cout << "BattleShip Sunk!!" << endl;;
				break;
			}

		}


	}


	if (board[l][r] == '@' && (board[l][r + 1] == '@' || board[l][r - 1] == '@')) {
		r++;
		for (int i = 0; i < 5; i++, r++) {
			if (board[l][r] == 'S')
				break;
			if (board[l][r] != 'S' && board[l][r] != '@')
				flag = 1;

			if (board[l][r - (i + 2)] == 'S')
				break;
			if (i == 0 && (board[l][r - (i + 2)] != 'S' || board[l][r - (i + 2)] != '@'))
				flag2 = 1;
			if (i != 0 && (board[l][r - (i + 2)] != 'S' || board[l][r - (i + 2)] != '@'))
				flag2 = 1;
			if (flag == 1 && flag2 == 1) {
				cout << "BattleShip Sunk!!" << endl;;
				break;
			}

		}





	}
}

void game::play()
{

	char xy[4];
	int x, y, rounds = 0;
	ClearBoard();
	BuildBoard();
	char hint;
	cout << " Do you want a hint?[y/n]" << endl;
	cin >> hint;
	getchar();
	if (hint == 'y') {
		PrintOriginalBoard();
		cout << endl;
		cout << "memorize the board and press enter to start the game.." << endl;
	}
	while (cells_taken != 0) {
		rounds++;
		cout << "Enter Guess: x y (to exit use 0 0)" << endl;
		cin.getline(xy, 256);
		if (xy[0] == '0' && xy[2] == '0')
			cout << "Thank you for playing" << endl;
		if (xy[0] != 'j')
			x = xy[0] - 97;
		if (xy[0] == 'j')
			x = 9;
		y = xy[2] - 49;
		if (xy[2] == '1' && xy[3] == '0')
			y = 9;
		CheckHit(y, x);
		CheckSunk(y, x);
		PrintBoard();

	}
	if (cells_taken == 0) {
		cout << "WIN!!!" << endl;
		cout << " you had " << rounds << " " << "rounds total." << endl;
		PrintOriginalBoard();
		cout << endl;
		cout << "Press any key to continue..." << endl;
		getchar();
		getchar();

	}
}
