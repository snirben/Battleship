/*Assignment: 2
Campus : Beer Sheva
	Author : Snir Ben Yosef, ID : 307908699
	*/
#include "game.h"
#include "battleship.h"


int main() {
	char playmore='y'; // char value to know if to start new game
	while (playmore == 'y') { // while to loop the game if need.
		game game1;
		game1.play();
		cout << "do you want to play more?[y/n]" << endl; //output 
		cin >> playmore; //input
		getchar();
	}
	return 0;
}