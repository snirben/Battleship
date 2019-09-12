/*Assignment: 2
Campus : Beer Sheva
	Author : Snir Ben Yosef, ID : 307908699
	*/
#ifndef _Battleship_h
#define _Battleship_h
#include <iostream>
#include <ctime>
using namespace std;

class battleship {
private:
	int size; // size of ship
	static int already_placed; // static to know how much is been placed
public:
	battleship(); // ctor
	void setsize(int); // set the size func
	int getsize() {
		return size;
	};


};
#endif