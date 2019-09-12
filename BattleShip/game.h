/*Assignment: 2
Campus : Beer Sheva
	Author : Snir Ben Yosef, ID : 307908699
	*/
#ifndef _Battleship2_h
#define _Battleship2_h
#include "battleship.h"



class game {
private:
	char board[10][10]; //create board 10/10
	battleship* ships; //create ships pointer depends on the user
	int number_of_ships; // how much ships?
	int CheckPlace(int, int, int, int); // check if place as been taken or valid
	void BuildBoard(); // func to build the board
	static int cells_taken; // static value
public:
	game(); //ctor
	~game();// dtor
	void ClearBoard(); //clear the board
	void PrintBoard(); // print the board without the ships
	void PrintOriginalBoard(); // hint
	void CheckHit(int,int); // check if user hit
	void CheckSunk(int,int); // check if sunk
	void play(); // play func



};

#endif